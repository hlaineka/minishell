/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:24:50 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/01 17:40:08 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	create_new_path(char **absolute_path, int i, char *new_dir, int *symlinks)
{
	char	*temp_path;
	
	if (i == 0 && ft_strequ(new_dir, "."))
			i++;
		else if (ft_strequ(new_dir, ".."))
		{
			temp_path = ft_strsub(*absolute_path, 0, ft_str_rfind_c(*absolute_path, '/'));
			free(*absolute_path);
			*absolute_path = temp_path;
			*symlinks = *symlinks + 1;
		}
		else
		{
			temp_path = ft_strjoin3(*absolute_path, "/", new_dir);
			free(*absolute_path);
			*absolute_path = temp_path;
		}
}

int		check_path(char **path, t_editor *info)
{
	int			symlinks;
	char		**directories;
	int			i;
	char		*absolute_path;
	char		*temp_path;
	struct stat	*stat_buf;

	if (ft_strlen(path) > 255)
	{
		ft_printf("%rcd: Filename too long\n");
		return (-1);
	}
	if (*path[0] == '/')
	{
		absolute_path = ft_strdup("/");
		temp_path = ft_strdup(*path);
	}
	else
	{	
		temp_path = ft_strjoin3(get_pwd(info->envp_pointer), "/", *path);
		absolute_path = ft_strnew(1);
	}
	directories = ft_strsplit(temp_path, '/');
	ft_free(temp_path);
	symlinks = 0;
	i = 0;
	while (directories[i])
	{
		stat_buf = (struct stat*)malloc(sizeof(struct stat));
		create_new_path(&absolute_path, i, directories[i], &symlinks);
		if (0 != access(absolute_path, F_OK))
		{
			ft_printf("%rcd: No such file or directory: %s\n", *path);
			return (-1);
		}
		else if (0 != access(absolute_path, X_OK))
		{
			ft_printf("%rcd: Permission denied\n");
			return (-1);
		}
		else if (0 != stat(absolute_path, stat_buf))
		{
			ft_printf("%rcd: Unknown error happened\n");
			return (-1);
		}
		else if (S_ISLNK(stat_buf->st_mode))
		{
			symlinks++;
			if (symlinks > 3)
			{	
				ft_printf("%rcd: Too many levels of symbolic links\n");
				return (-1);
			}
		}
		else if (!S_ISDIR(stat_buf->st_mode))
		{
			ft_printf("%rcd: Not a directory: %s\n", *path);
			return (-1);
		}
		ft_free(stat_buf);
	}
	ft_free(*path);
	*path = absolute_path;
	return (0);
}

int		cd_home(t_editor *info)
{
	char	*homedir;
	
	homedir = ft_getenv(info->envp_pointer, "HOME");
	if (!homedir)
	{
		ft_printf("%rcd: HOME not set");
		return(-1);
	}
	
	return(0);
}

int		ft_cd(char **argv, t_editor *info){

	if (ft_array_length(argv) > 3)
	{
		ft_putstr_fd("cd: too many arguments", 2);
		return -1;
	}
	if (ft_array_length(argv) == 1)
		return(cd_home(info));
	if (info)
		return (0);
	else return (1);
}