/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 13:37:18 by hlaineka          #+#    #+#             */
/*   Updated: 2020/12/09 11:54:43 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	process_key_press(t_editor *info)
{
	char		*command;
	int			i;
	t_list		*temp_list;

	i = 0;
	command = (char*)malloc(sizeof(char));
	command = NULL;
	while (!command || !ft_strequ(command, "exit"))
	{
		ft_free(command);
		command = ft_strnew(1);
		ft_putstr("$>");
		temp_list = info->command_buf;
		info->cursorshift = 0;
		while ((i = read_key_press(&command, info)) != 10)
		{
			if (i == UP)
				temp_list = arrow_up(&command, info, temp_list);
			//if (i == DOWN)
			else if (i == LEFT)
				arrow_left(info, command);
			else if (i == RIGHT)
				arrow_right(info, command);
			else if (info->cursorshift != 0)
			{
				if (i == 127 && (ft_strlen(command) + info->cursorshift > 0))
					delete_middle(&command, info);
				else
					add_char_to_middle(&command, info, i);
			}
		}
		if (command)
		{
			ft_printf("\n");
			add_command(command, info);
			check_command(command, info);
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
	process_key_press(info);
	exitprocess(info);
}