/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_editing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:11:40 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/08 12:57:32 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
** ascii 39 == ' ascii 34 == "
*/

char	*delete_last(char *command, t_editor *info)
{
	char	*returnable;

	returnable = NULL;
	if (command[ft_strlen(command) -1] == 34)
		info->quote_open = !info->quote_open;
	if (command[ft_strlen(command) -1] == 39)
		info->singlequote_open = !info->singlequote_open;
	if (command)
	{
		returnable = ft_strsub(command, 0, ft_strlen(command) - 1);
		reprint_row(returnable, ft_strlen(returnable) + 1, 0);
	}
	return(returnable);
}

int		handle_esc(char c, char *command, char **temp)
{
	int 	returnable;
	char	a;
	char	b;
	
	
	read(STDIN_FILENO, &a, 1);
	read(STDIN_FILENO, &b, 1);
	returnable = c * 100 + a;
	returnable = returnable * 100 + b;
	if (returnable == UP || returnable == DOWN || returnable == LEFT
	|| returnable == RIGHT)
		return(returnable);
	*temp = ft_strdup(command);
	returnable = 0;
	return(returnable);
}

char	*handle_printable(char *command, char c, t_editor *info)
{
	char	*returnable;

	if (c == 10 && !info->quote_open && !info->singlequote_open)
		return (ft_strdup(command));
	if (c == 34)
		info->quote_open = !info->quote_open;
	else if (c == 39)
		info->singlequote_open = !info->singlequote_open;
	if (c == '\t')
	{
		returnable = ft_strjoin(command, "    ");
		ft_putstr("    ");
	}
	else
	{
		returnable = ft_str_char_join(c, command);
		if (c != '\n')
			ft_putchar(c);
	}
	return(returnable);
}

void	delete_middle(char **command, t_editor *info)
{
	char *temp;
	
	if (command[0][ft_strlen(*command) + info->cursorshift] == 34)
		info->quote_open = !info->quote_open;
	if (command[0][ft_strlen(*command) + info->cursorshift] == 39)
		info->singlequote_open = !info->singlequote_open;
	temp = ft_str_deli(*command, ft_strlen(*command) + info->cursorshift - 1);
	ft_free(*command);
	*command = temp;
	reprint_row(*command, ft_strlen(*command) + info->cursorshift, info->cursorshift);
}

void	add_char_to_middle(char **command, t_editor *info, char i)
{	
	char *temp;

	if (i == 10)
		return ;
	if (i == 34)
		info->quote_open = !info->quote_open;
	else if (i == 39)
		info->singlequote_open = !info->singlequote_open;
	temp = ft_str_addi(*command, ft_strlen(*command) + info->cursorshift, i);
	ft_free(*command);
	*command = temp;
	reprint_row(*command, ft_strlen(*command) + info->cursorshift - 1, info->cursorshift);
}