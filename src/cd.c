/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:24:50 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/04 16:28:18 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	create_new_path(char **absolute_path, int i, char *new_dir)
{
	char	*temp_path;
	
	if (i == 0 && ft_strequ(new_dir, "."))
			i++;
		else if (ft_strequ(new_dir, ".."))
		{
			temp_path = ft_strsub(*absolute_path, 0, ft_str_rfind_c(*absolute_path, '/'));
			free(*absolute_path);
			*absolute_path = temp_path;
		}
		else
		{
			temp_path = ft_strjoin3(*absolute_path, "/", new_dir);
			free(*absolute_path);
			*absolute_path = temp_path;
		}
}

int		check_path_errors(char *path)
{
	struct stat	*stat_buf;

	stat_buf = (struct stat*)malloc(sizeof(struct stat));
	if (0 != lstat(path, stat_buf))
	{
		ft_free(stat_buf);
		if (0 != access(path, F_OK))
			return (print_errorstr(2, "cd", path));
		else if (0 != access(path, X_OK))
			return (print_errorstr(13, "cd", path));
		return (print_errorstr(41, "cd", path));
	}
	else if (S_ISLNK(stat_buf->st_mode))	
	{
		ft_free(stat_buf);
		return (print_errorstr(40, "cd", path));
	}
	else if (0 != stat(path, stat_buf))
	{	
		ft_free(stat_buf);
		return (print_errorstr(41, "cd", path));
	}
	else if (!S_ISDIR(stat_buf->st_mode))
	{
		ft_free(stat_buf);
		return (print_errorstr(20, "cd", path));
	}
	ft_free(stat_buf);
	return (1);
}

int		check_path(char **path, t_editor *info)
{
	char		**directories;
	int			i;
	char		*absolute_path;
	char		*temp_path;
	char		*temp;

	absolute_path = ft_strnew(1);
	if (*path[0] == '/')
		temp_path = ft_strdup(*path);
	else if (-1 != getenv_index(info->envp_pointer, "CDPATH"))
	{	
		temp = ft_getenv(info->envp_pointer, "CDPATH");
		temp_path = ft_strjoin3(temp, "/", *path);
		ft_free(temp);
	}
	else
	{
		temp = get_pwd(info->envp_pointer);
		temp_path = ft_strjoin3(temp, "/", *path);
		ft_free(temp);
	}
	if (ft_strlen(temp_path) > 255)
		return (print_errorstr(36, "cd", temp_path));
	//ft_printf(temp_path);
	directories = ft_strsplit(temp_path, '/');
	ft_free(temp_path);
	i = 0;
	while (directories[i])
	{
		create_new_path(&absolute_path, i, directories[i]);
		if (-1 == (check_path_errors(absolute_path)))
			return (-1);
		i++;
	}
	ft_free(*path);
	*path = absolute_path;
	ft_strarray_free(directories);
	return (0);
}

int		cd_home(t_editor *info, char **path)
{
	char	*homedir;
	
	homedir = ft_getenv(info->envp_pointer, "HOME");
	if (!homedir)
	{
		ft_printf("%rcd: HOME not set");
		return(-1);
	}
	*path = ft_strdup(homedir);
	ft_free(homedir);
	return(0);
}

int		ft_cd(char **argv, t_editor *info){

	char		*path;
	char		*temp;
	char		*temp2;
	
	path = NULL;
	temp = NULL;
	if (ft_array_length(argv) > 2)
	{
		ft_putstr_fd("cd: too many arguments", 2);
		return -1;
	}
	if (ft_array_length(argv) == 1)
	{	
		if (-1 == cd_home(info, &path))
			return (-1);
	}
	else 
		path = ft_strdup(argv[1]);
	if (-1 == (check_path(&path, info)))
	{
		ft_free(path);
		return (-1);
	}
	if (-1 == (chdir(path)))
	{
		ft_free(path);
		return (print_errorstr(41, "cd-chdir", path));
	}
	temp = ft_strjoin3("PWD", "=", path);
	ft_free(path);
	path = ft_strdup(temp);
	ft_free(temp);
	temp2 = ft_getenv(info->envp_pointer, "PWD");
	temp = ft_strjoin3("OLDPWD", "=", temp2);
	ft_free(temp2);
	info->envp_pointer = add_str_to_env(info->envp_pointer, temp, getenv_index(info->envp_pointer, "OLDPWD"));
	info->envp_pointer = add_str_to_env(info->envp_pointer, path, getenv_index(info->envp_pointer, "PWD"));
	ft_free(temp);
	ft_free(path);
	return (0);
}