/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:08:29 by hlaineka          #+#    #+#             */
/*   Updated: 2020/10/13 15:09:54 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	add_string_to_cursor(t_editor *info, char *printable)
{
	int	i;

	i = 0;
	while(printable[i])
	{
		if (printable[i] == '\n' || info->cursorcol + 1 == info->screencols)
		{
			info->cursorrow++;
			info->cursorcol = 1;
		}
		else
			info->cursorcol++;
		i++;
	}
}

void	remove_string_from_cursor(t_editor *info, char *printable)
{
	int	i;

	i = 0;
	while(printable[i])
	{
		if (printable[i] == '\n' || info->cursorcol <= 2)
		{
			info->cursorrow--;
			info->cursorcol = 1;
		}
		else
			info->cursorcol--;
		i++;
	}
}

void	add_char_to_cursor(t_editor *info, char c)
{
	if (c == '\n' || info->cursorcol + 1 == info->screencols)
	{
		info->cursorrow++;
		info->cursorcol = 2;
	}
	else
		info->cursorcol++;
}

void	cursor_to_left(t_editor *info)
{
	if (info->cursorcol > 2)
		info->cursorcol--;
}