/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:47:09 by hlaineka          #+#    #+#             */
/*   Updated: 2020/11/03 14:30:18 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	check_command(char *command, t_editor *info)
{
	char	**temp_argv;
	pid_t	child_pid;
	int		child_status;
	char	*path_executable;

	path_executable = NULL;
	temp_argv = ft_strsplit(command, ' ');
	if (ft_strequ(temp_argv[0], "exit"))
				exitprocess(info);
	if (ft_strequ(temp_argv[0], "env"))
	{
		print_env(info);
		return ;
	}
	if (ft_strequ(temp_argv[0], "setenv"))
	{
		ft_setenv(temp_argv, info->envp_pointer);
		return ;
	}
	if (ft_strequ(temp_argv[0], "info"))
	{
		print_info();
		return ;
	}
	else if (!(check_executable(info, temp_argv[0], &path_executable)))
	{
		ft_printf("command not found: %s\n", temp_argv[0]);
		return ;
	}
	child_pid = fork();
	if (child_pid == 0)
	{
		execve(path_executable, temp_argv, info->envp_pointer);
		ft_printf("command not found: %s\n", temp_argv[0]);
		exit(0);
	}
	else
		wait(&child_status);
}

int		check_executable(t_editor *info, char *executable, char **path_executable)
{
	char		**temp_strarray;
	char		*path_env;
	char		*temp;
	int			i;
	struct stat	temp_stat;
	
	i = 0;
	path_env = NULL;
	temp = NULL;
	path_env = ft_getenv(info->envp_pointer, "PATH");
	if (!path_env)
		return (0);
	temp_strarray = ft_strsplit(path_env, ':');
	i = 0;
	while (temp_strarray[i])
	{
		temp = ft_strjoin3(temp_strarray[i], "/", executable);
		if (stat(temp, &temp_stat) == 0)
		{
			*path_executable = ft_strdup(temp);
			free(temp);
			return(1);
		}
		free(temp);
		i++;
	}
	return (0);
}