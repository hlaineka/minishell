/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:47:09 by hlaineka          #+#    #+#             */
/*   Updated: 2020/10/29 18:52:12 by hlaineka         ###   ########.fr       */
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
				exit(0);
	if (ft_strequ(temp_argv[0], "env"))
		path_executable = ft_strjoin("programs/", temp_argv[0]);
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
	temp_strarray = info->envp_pointer;
	while(temp_strarray[i])
	{
		temp = ft_strsub(temp_strarray[i], 0, 4);
		if (ft_strequ(temp, "PATH"))
			path_env = ft_strsub(temp_strarray[i], 5, ft_strlen(temp_strarray[i]));
		free(temp);
		i++;
	}
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