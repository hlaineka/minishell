/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 13:37:18 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:24:31 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Prints the prompt (in this shell "$>") reads the input throug lexer()
** adds the command to the info with add_command() and starts scanner()
** to analyse and execute the command.
*/

void	prompt(t_editor *info)
{
	char		*command;

	command = NULL;
	while (!command || !ft_strequ(command, "exit"))
	{
		ft_free(command);
		ft_putstr("$>");
		command = lexer(info);
		ft_printf("\n");
		if (command)
		{
			add_command(command, info);
			scanner(command, info);
		}
	}
}

/*
** starts the minishell. First allocates and initiates the t_editor pointer,
** that saves most of the data used by the shell. Enables rawmode, clears the
** screen and start the shell by calling on the function prompt.
*/

int		main(int argc, char **argv, char **envp)
{
	t_editor	*info;

	if (argc != 1 || argv[0][0] != '.')
		return (0);
	info = (t_editor*)malloc(sizeof(t_editor));
	info->command_buf = NULL;
	info->print_buf = NULL;
	info->cursorshift = 0;
	info->envp_pointer = ft_strarr_copy(envp);
	enable_rawmode(info);
	check_window_size(info);
	clear_screen();
	prompt(info);
	exitprocess(argv, info);
}
