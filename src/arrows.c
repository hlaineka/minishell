/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 14:56:41 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/13 21:04:39 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
** Handles the arrow up by updating the current command to the next one.
** Reprints the row by moving the cursor to the left the length of the
** command, then clears the row from that point forward and writes the
** new command.
*/

t_list	*arrow_up(char **command, t_list *command_list)
{
	int		command_length;

	command_length = 0;
	if (command_list)
	{
		if (*command)
			command_length = ft_strlen(*command);
		while (command_length > 0)
		{
			ft_printf("\033[D");
			command_length--;
		}
		ft_free(*command);
		ft_printf("\033[K");
		*command = ft_strdup((char*)command_list->content);
		ft_printf(*command);
		return (command_list->next);
	}
	return (NULL);
}

/*
** Checks that the cursor does not go too far left by comparing
** the length of the command and cursorshift counter
*/

void	arrow_left(t_editor *info, char *command)
{
	if (ft_strlen(command) + info->cursorshift > 0)
	{
		info->cursorshift--;
		ft_printf("\033[D");
	}
}

/*
** checks that cursor does not move right from the last character
** by checking cursorshift counter. If cursor is at the end of the
** screen, moves it to the next line and two chars to the right
** (the lenght of the prompt)
*/

void	arrow_right(t_editor *info)
{
	if (info->cursorshift < 0)
	{
		info->cursorshift++;
		if (!save_cursor_position(info))
			return ;
		if (info->cursorcol + 1 == info->screencols)
		{
			ft_printf("\033[B");
			ft_printf("\033[2C");
		}
		else
			ft_printf("\033[C");
	}
}
