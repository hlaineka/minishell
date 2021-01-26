/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:39:26 by hlaineka          #+#    #+#             */
/*   Updated: 2021/01/26 16:33:23 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		print_env(char** temp_envp)
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

int		print_envusage(int error, char c)
{
	if (error == 1)
		ft_printf("%renv: option requires an argument -- u\n");
	if (error == 2)
		ft_printf("%renv: illegal option -- %c\n", c);
	ft_printf("%r   usage: env [-i] [-u name]\n   [name=value ...] [utility [argument ...]]\n");
	return(0);
}

int		check_options(char ***temp_argv, char **argv, char ***temp_envp)
{
	int 	i;
	char	*temp;

	i = 1;
	if (ft_array_length(argv) == 1)
		return(print_env(*temp_envp));
	while(argv && argv[i])
	{
		if (argv[i][0] == '-' && !*temp_argv)
		{
			if (argv[i][1] == 'i')
			{
				ft_strarray_free(*temp_envp);
				*temp_envp = (char**)malloc(sizeof(char*));
				*temp_envp = NULL;
				ft_strarr_add(*temp_envp, "\0");
				if (!argv[i + 1])
					return(print_env(*temp_envp));
			}
			else if (argv[i][1] == 'u')
			{
				if (!argv[i + 1])
					return(print_envusage(1, 'u'));
				*temp_envp = ft_envhelper_unset(argv[i + 1], *temp_envp);
				if (!argv[i + 2])
					return (print_env(*temp_envp));
			}
			else
				return(print_envusage(2, argv[i][1]));
		}
		else if (ft_strchr(argv[i], '=') && !*temp_argv)
		{
			temp = ft_strsub(argv[i], 0, ft_str_find_c(argv[i], '='));
			*temp_envp = add_str_to_env(*temp_envp, argv[i], getenv_index(*temp_envp, temp));
			free(temp);
			if (!argv[i + 1])
				return(print_env(*temp_envp));
		}
		else
			*temp_argv = ft_strarr_add(*temp_argv, argv[i]);
		i++;
	}
	return (1);
}

void	ft_env(char **argv, t_editor *info)
{
	char**		temp_envp;
	char**		temp_argv;
	pid_t		child_pid;
	int			child_status;
	char		*path_executable;

	temp_envp = ft_strarr_copy(info->envp_pointer);
	temp_argv = (char**)malloc(sizeof(char*));
	temp_argv = NULL;
	if (!(check_options(&temp_argv, argv, &temp_envp)))
		return ;
	if (!(check_executable(info, temp_argv[0], &path_executable)))
		{
			ft_printf("%rcommand not found: %s\n", temp_argv[0]);//
			return ;
		}
		child_pid = fork();
		if (child_pid == 0)
		{
			execve(path_executable, temp_argv, temp_envp);
			ft_printf("%rcommand not found: %s\n", temp_argv[0]);
			exit(0);
		}
		else
			wait(&child_status);
	ft_strarray_free(temp_envp);
	ft_strarray_free(temp_argv);
}