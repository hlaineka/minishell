/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:47:09 by hlaineka          #+#    #+#             */
/*   Updated: 2020/10/28 14:20:27 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	check_command(char *command, t_editor *info)
{
	char	**temp_argv;
	pid_t	child_pid;
	int		child_status;
	//pid_t	wait_pid;

	temp_argv = ft_strsplit(command, ' ');
	if (ft_strequ(command, "ENV"))
		print_env(info);
	else
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			if (ft_strequ(temp_argv[0], "ls"))
				execve("/Users/helvi/Documents/hive/minishell/programs/ft_ls/ft_ls", temp_argv, info->envp_pointer);
			if (ft_strequ(temp_argv[0], "exit"))
				exit(0);
			ft_printf("command not found: %s\n", temp_argv[0]);
			exit(0);
		}
		else
			wait(&child_status);
	}
	//write(1, &'\033[6n', 1);
}