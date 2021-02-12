/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:27:20 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/12 21:25:39 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		check_buildins(t_editor *info, char** temp_argv, char **envp)
{
		if (!temp_argv)
			return (-1);
		if (ft_strequ(temp_argv[0], "exit"))
			exitprocess(temp_argv, info);
		if (ft_strequ(temp_argv[0], "env"))
		{
			ft_env(temp_argv, info, envp);
			return 1;
		}
		if (ft_strequ(temp_argv[0], "setenv"))
		{
			ft_setenv(temp_argv, info);
			return 1;
		}
		if (ft_strequ(temp_argv[0], "info"))
		{
			print_info();
			return 1;
		}
		if (ft_strequ(temp_argv[0], "unsetenv"))
		{
			ft_unsetenv(temp_argv, info);
			return 1;
		}
		if (ft_strequ(temp_argv[0], "echo"))
		{
			ft_echo(temp_argv);
			return 1;
		}
		if (ft_strequ(temp_argv[0], "pwd"))
		{
			ft_pwd(envp);
			return 1;
		}
		if (ft_strequ(temp_argv[0], "cd"))
		{
			ft_cd(temp_argv, info);
			return 1;
		}
		return 0;
}

void	command_execute(t_command *commands, t_editor *info)
{
	char		**temp_argv;
	pid_t		child_pid;
	int			child_status;
	char		*path_executable;

	temp_argv = NULL;
	while (commands)
	{
		path_executable = NULL;
		temp_argv = commands->command_argv;
		if (!temp_argv || ft_strlen(temp_argv[0]) == 0)
			return;
		if (0 != (check_buildins(info, temp_argv, info->envp_pointer)))
			return ;
		else if (!(check_executable(info, temp_argv[0], &path_executable)))
		{
			ft_printf("%rcommand not found: %s\n", temp_argv[0]);//
			return ;
		}
		child_pid = fork();
		if (child_pid == 0)
		{
			execve(path_executable, temp_argv, info->envp_pointer);
			ft_printf("%rcommand not found: %s\n", temp_argv[0]);
			exit(0);
		}
		else
			wait(&child_status);
		commands = commands->next_command;
		ft_free(path_executable);
	}
}

/*
** Goes through all the directories in the PATH environment variable, and checks
** if the executable exists with stat. Copies the right path to path_executable
** parameter.
*/
int		check_executable(t_editor *info, char *executable, char **path_executable)
{
	char		**temp_strarray;
	char		*path_env;
	char		*temp;
	int			i;
	struct stat	temp_stat;
	
	if (executable[0] == '.' || executable [0] == '/')
	{
		*path_executable = ft_strdup(executable);
		return(1);
	}
	i = 0;
	path_env = NULL;
	temp = NULL;
	path_env = ft_getenv(info->envp_pointer, "PATH");
	if (!path_env)
		return (0);
	temp_strarray = ft_strsplit(path_env, ':');
	ft_free(path_env);//
	i = 0;
	while (temp_strarray[i])
	{
		temp = ft_strjoin3(temp_strarray[i], "/", executable);
		if (stat(temp, &temp_stat) == 0)
		{
			*path_executable = ft_strdup(temp);
			ft_strarray_free(temp_strarray);
			ft_free(temp);
			return(1);
		}
		ft_free(temp);
		i++;
	}
	ft_strarray_free(temp_strarray);
	return (0);
}