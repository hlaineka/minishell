/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 13:37:18 by hlaineka          #+#    #+#             */
/*   Updated: 2020/12/17 14:22:06 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	prompt(t_editor *info)
{
	char		*command;

	command = (char*)malloc(sizeof(char));
	command = NULL;
	while (!command || !ft_strequ(command, "exit"))
	{
		ft_free(command);
		ft_putstr("$>");
		command = lexer(info);
		if (command)
		{
			ft_printf("\n");
			add_command(command, info);
			scanner(command, info);
		}
	}
}

int		main(int argc, char **argv, char **envp)
{
	t_editor	*info;
	
	if (argc != 1 || argv[0][0] != '.')
		return(0);
	info = (t_editor*)malloc(sizeof(t_editor));
	info->command_buf = NULL;
	info->print_buf = NULL;
	info->cursorshift = 0;
	info->envp_pointer = ft_strarr_copy(envp);
	enable_rawmode(info);
	check_window_size(info);
	clear_screen();
	prompt(info);
	exitprocess(info);
}