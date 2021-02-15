/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:39:26 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/14 18:19:46 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
** The functions to execute the build in env. Takes arguments -i, -u [name]
** and multiple [VAR=value] pairs. Executes the program given as a parameter
** with the modified envp argument.
*/

/*
** Prints the envp variable.
*/

int			print_env(char **temp_envp)
{
	int			i;

	i = 0;
	while (temp_envp && temp_envp[i])
	{
		ft_putstr(temp_envp[i]);
		ft_putstr("\n");
		i++;
	}
	return (0);
}

/*
** If the input for env is not acceptable, this function prints the
** usage for env.
*/

int			print_envusage(int error, char c)
{
	if (error == 1)
		ft_printf("%renv: option requires an argument -- u\n");
	if (error == 2)
		ft_printf("%renv: illegal option -- %c\n", c);
	ft_printf("%r   usage: env [-i] [-u name] [name=value ...]");
	ft_printf(" [utility [argument ...]]\n");
	return (0);
}

/*
** Goes through the argv given to env, and creates a new argv for the
** possible executable as well as a temporary envp variable.
*/

static int	check_options(char ***temp_argv, char **argv, char ***temp_envp)
{
	int		i;

	i = 1;
	if (ft_array_length(argv) == 1)
		return (print_env(*temp_envp));
	while (argv && argv[i])
	{
		if (argv[i][0] == '-' && !*temp_argv)
		{
			if (0 == handle_env_parameter(argv, &i, temp_envp))
				return (0);
		}
		else if (ft_strchr(argv[i], '=') && !*temp_argv)
		{
			if (0 == handle_new_env(argv, i, temp_envp))
				return (0);
		}
		else
			*temp_argv = ft_strarr_add(*temp_argv, argv[i]);
		i++;
	}
	return (1);
}

/*
** The main function of handling env. Checks the input and possible
** options with check_options(), then checks if the given argument is a
** buildit and runs it. If not, checkes if the executable exists and
** runs the command on a fork with the temporary envp variable created
** by this function.
*/

int			ft_env(char **argv, t_editor *info, char **envp)
{
	char		**temp_envp;
	char		**temp_argv;
	pid_t		child_pid;
	int			child_status;
	char		*path_executable;

	temp_envp = ft_strarr_copy(envp);
	temp_argv = NULL;
	if (!(check_options(&temp_argv, argv, &temp_envp)))
		return (env_free(temp_envp, temp_argv));
	if (1 == check_buildins(info, temp_argv, &temp_envp))
		return (env_free(temp_envp, temp_argv));
	if (!(check_executable(temp_envp, temp_argv[0], &path_executable)))
		return (env_command_nf(temp_envp, temp_argv));
	child_pid = fork();
	if (child_pid == 0)
	{
		execve(path_executable, temp_argv, temp_envp);
		env_command_nf(temp_envp, temp_argv);
		exit(0);
	}
	else
		wait(&child_status);
	env_free(temp_envp, temp_argv);
	return (1);
}
