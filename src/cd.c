/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:24:50 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/13 12:58:46 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	create_new_path(char **absolute_path, char *new_dir)
{
	char	*temp_path;
	
	if (ft_strequ(new_dir, "."))
		return;
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
	
	if (ft_strlen(path) >= 255)
		return (print_errorstr(36, "cd", path));
	if (0 != access(path, F_OK))
			return (print_errorstr(2, "cd", path));
	if (0 != access(path, X_OK))
			return (print_errorstr(13, "cd", path));
	stat_buf = (struct stat*)malloc(sizeof(struct stat));
	if (-1 == lstat(path, stat_buf))
	{
		ft_free(stat_buf);
		return (print_errorstr(41, "cd: lstat fail", path));
	}
	else if (S_ISLNK(stat_buf->st_mode))	
	{
		ft_free(stat_buf);
		return (print_errorstr(40, "cd", path));
	}
	else if (-1 == stat(path, stat_buf))
	{	
		ft_free(stat_buf);
		return (print_errorstr(41, "cd: stat fail", path));
	}
	else if (!S_ISDIR(stat_buf->st_mode))
	{
		ft_free(stat_buf);
		return (print_errorstr(20, "cd", path));
	}
	ft_free(stat_buf);
	return (1);
}

int		check_path(char **path, char **envp)
{
	char		**directories;
	int			i;
	char		*absolute_path;
	char		*temp_path;
	char		*temp;

	absolute_path = ft_strnew(1);
	if (*path[0] == '/' || *path[0] == '~')
		temp_path = ft_strdup(*path);
	else if (-1 != getenv_index(envp, "CDPATH"))
	{	
		temp = ft_getenv(envp, "CDPATH");
		temp_path = ft_strjoin3(temp, "/", *path);
		ft_free(temp);
	}
	else
	{
		temp = get_pwd(envp);
		temp_path = ft_strjoin3(temp, "/", *path);
		ft_free(temp);
	}
	if (ft_strlen(temp_path) > 255)
		return (print_errorstr(36, "cd", temp_path));
	directories = ft_strsplit(temp_path, '/');
	ft_free(temp_path);
	i = 0;
	while (directories[i])
	{
		create_new_path(&absolute_path, directories[i]);
		if (-1 == (check_path_errors(absolute_path)))
		{
			ft_free(absolute_path);
			ft_strarray_free(directories);
			return (-1);
		}
		i++;
	}
	ft_free(*path);
	*path = absolute_path;
	ft_strarray_free(directories);
	return (0);
}

int		cd_home(char **envp, char **path)
{
	char	*homedir;
	
	homedir = ft_getenv(envp, "HOME");
	if (!homedir)
	{
		ft_printf("%rcd: HOME not set");
		return(-1);
	}
	*path = ft_strdup(homedir);
	ft_free(homedir);
	return(0);
}

int		ft_cd(char **argv, char ***envp){

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
		if (-1 == cd_home(*envp, &path))
			return (-1);
	}
	else if (ft_strequ(argv[1], "-"))
	{
		if (-1 == getenv_index(*envp, "OLDPWD"))
		{
			ft_putstr_fd("cd: OLDPWD not set\n", 2);
			return (-1);
		}
		path = ft_getenv(*envp, "OLDPWD");
	}
	else 
		path = ft_strdup(argv[1]);
	if (-1 == (check_path(&path, *envp)))
	{
		ft_free(path);
		return (-1);
	}
	if (-1 == (chdir(path)))
	{
		ft_free(path);
		return (print_errorstr(41, "cd: chdir fail", path));
	}
	temp = ft_strjoin3("PWD", "=", path);
	ft_free(path);
	path = ft_strdup(temp);
	ft_free(temp);
	temp2 = ft_getenv(*envp, "PWD");
	temp = ft_strjoin3("OLDPWD", "=", temp2);
	ft_free(temp2);
	*envp = add_str_to_env(*envp, temp, getenv_index(*envp, "OLDPWD"));
	*envp = add_str_to_env(*envp, path, getenv_index(*envp, "PWD"));
	ft_free(temp);
	ft_free(path);
	return (0);
}