/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:27:20 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/15 12:19:31 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
** Command execute is called by the scanner with a commands list, where the
** argv arguments are stored. Command execute checks if the command is a build
** in, or if not, is there an executable of that name. Adds the path of the
** executable from PATH env variable when needed.
** Also the build in env uses the functions in this file when executing a
** command with temporary envp argument.
*/

/*
** Checks it the first string of an argv argument is a name of a build in
** function and if so, executes that command. Returns 1 if the command was
** found, and a 0 if not.
*/

int				check_buildins(t_editor *info, char **temp_argv, char ***envp)
{
	if (!temp_argv || !temp_argv[0])
		return (-1);
	if (ft_strequ(temp_argv[0], "exit"))
		exitprocess(temp_argv, info);
	if (ft_strequ(temp_argv[0], "env"))
		return (ft_env(temp_argv, info, *envp));
	if (ft_strequ(temp_argv[0], "setenv"))
		return (ft_setenv(temp_argv, envp));
	if (ft_strequ(temp_argv[0], "info"))
		return (print_info());
	if (ft_strequ(temp_argv[0], "unsetenv"))
		return (ft_unsetenv(temp_argv, envp));
	if (ft_strequ(temp_argv[0], "echo"))
		return (ft_echo(temp_argv));
	if (ft_strequ(temp_argv[0], "pwd"))
		return (ft_pwd(*envp));
	if (ft_strequ(temp_argv[0], "cd"))
		return (ft_cd(temp_argv, envp));
	return (0);
}

/*
** check_patharr function check a array of strings created from the envp
** PATH variable and checks if the executable exist with that path. If the
** executable exist with stat() , saves it to the parameter path_executable
** and returns 1. If the executable was not found, returns 0.
*/

static int		check_patharr(char **patharr, char **path_executable,
				char *executable)
{
	int			i;
	char		*temp;
	struct stat	temp_stat;

	i = 0;
	temp = NULL;
	while (patharr[i])
	{
		temp = ft_strjoin3(patharr[i], "/", executable);
		if (stat(temp, &temp_stat) == 0)
		{
			*path_executable = ft_strdup(temp);
			ft_free(temp);
			return (1);
		}
		ft_free(temp);
		i++;
	}
	return (0);
}

/*
** checks if the path starts with . or /. if so, it is in it self the path
** for the executable. Otherwise creates a array of strings from the env
** PATH variable and sends it to check_patharr(). Returns 1 is an executable
** file is found, if not, returns 0.
*/

int				check_executable(char **envp, char *executable,
				char **path_executable)
{
	char		**temp_strarray;
	char		*path_env;
	int			returnable;

	if (executable[0] == '.' || executable[0] == '/')
	{
		*path_executable = ft_strdup(executable);
		return (1);
	}
	path_env = NULL;
	path_env = ft_getenv(envp, "PATH");
	if (!path_env)
		return (0);
	temp_strarray = ft_strsplit(path_env, ':');
	if (1 == check_patharr(temp_strarray, path_executable, executable))
		returnable = 1;
	else
		returnable = 0;
	ft_free(path_env);
	ft_strarray_free(temp_strarray);
	return (returnable);
}

/*
** The main function responsible of command execute. Goes through the commands
** list, uses check_buildins() to check if the first argument it is a buildin,
** if not, checks the if the first argument is an executable command with
** check_executable. After that runs a fork with the executable.
*/

void			command_execute(t_command *commands, t_editor *info)
{
	pid_t		child_pid;
	int			child_status;
	char		*path_executable;

	while (commands)
	{
		path_executable = NULL;
		if (0 != (check_buildins(info, commands->command_argv,
				&info->envp_pointer)))
			return ;
		else if (!(check_executable(info->envp_pointer,
				commands->command_argv[0], &path_executable)))
			return (errstrs("command not found: ", commands->command_argv[0]));
		child_pid = fork();
		if (child_pid == 0)
		{
			execve(path_executable, commands->command_argv, info->envp_pointer);
			ft_printf("%rcommand not found: %s\n", commands->command_argv[0]);
			exit(0);
		}
		else
			wait(&child_status);
		commands = commands->next_command;
		ft_free(path_executable);
	}
}
