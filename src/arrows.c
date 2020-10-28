/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 14:56:41 by hlaineka          #+#    #+#             */
/*   Updated: 2020/10/28 14:27:49 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_list	*arrow_up(char **command, t_editor *info, t_list *command_list)
{
	if (*command && command_list)
	{
		//remove_string_from_cursor(info, *command);
		//free(*command);
		*command = ft_strdup((char*)command_list->content);
		//add_string_to_cursor(info, *command);
		reprint_row(info, *command);
		return (command_list->next);
	}
	return (NULL);
}

void	arrow_left(t_editor *info, char *command)
{
	if (ft_strlen(command) + info->cursorshift > 0)
		info->cursorshift--;
	//cursor_to_left(info);
	reprint_row(info, command);
}

void	arrow_right(t_editor *info, char *command)
{
	if (info->cursorshift < 0)
	{	
		info->cursorshift++;
		add_char_to_cursor(info, 0);
	}
	reprint_row(info, command);
}