/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_printing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:10:31 by hlaineka          #+#    #+#             */
/*   Updated: 2020/10/28 14:39:08 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	clear_screen()
{
	write(STDOUT_FILENO, "\x1b[2J", 4);
	write(STDOUT_FILENO, "\x1b[H", 3);
}

void	print_screen(t_editor *info, char *command)
{
	t_list *temp;

	clear_screen();
	temp = info->print_buf;
	while (temp)
	{
		if (temp->content)
			ft_putstr((char*)temp->content);
		temp = temp->next;
	}
	if (command)
		ft_putstr(command);
	ft_printf("\x1b[%d;%dH", info->cursorrow, info->cursorcol);
}

void	reprint_row(t_editor *info, char *command)
{
	if (info)
	{
		ft_printf("\r");
		ft_printf("\033[K");
		if (command)
			ft_printf("\r$>%s", command);
	}
}

void	print_string(t_editor *info, char *printable)
{
	ft_lstnewtoend(printable, ft_strlen(printable), &(info->print_buf));
	ft_putstr(printable);
	add_string_to_cursor(info, printable);
}