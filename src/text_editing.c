/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_editing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:11:40 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:25:23 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Functions handling the output on the screen according to the input character
** given by the user. These functions are called by the check_keypress()
** function from lexer.c file.
*/

/*
** Deletes the last character of the input and returns the new string to the
** caller.
** ascii 39 == ' ascii 34 == "
*/

char	*delete_last(char *command, t_editor *info)
{
	char	*returnable;

	returnable = NULL;
	if (command[ft_strlen(command) - 1] == 34)
		info->quote_open = !info->quote_open;
	if (command[ft_strlen(command) - 1] == 39)
		info->singlequote_open = !info->singlequote_open;
	if (command)
	{
		returnable = ft_strsub(command, 0, ft_strlen(command) - 1);
		reprint_row(returnable, ft_strlen(returnable) + 1, 0);
	}
	return (returnable);
}

/*
** handles any esc character, like arrows.
*/

int		handle_esc(char c, char *command, char **temp)
{
	int		returnable;
	char	a;
	char	b;

	read(STDIN_FILENO, &a, 1);
	read(STDIN_FILENO, &b, 1);
	returnable = c * 100 + a;
	returnable = returnable * 100 + b;
	if (returnable == UP || returnable == DOWN || returnable == LEFT
	|| returnable == RIGHT)
		return (returnable);
	*temp = ft_strdup(command);
	returnable = 0;
	return (returnable);
}

/*
** if the character is printable, this functon is called. Handles quotes
** and tabulation separately.
*/

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
	return (returnable);
}

/*
** Deletes a character in the middle of the input. Is called when the user
** inputs a delete and the cursor has been moved from the end of the input.
*/

char	*delete_middle(char *command, t_editor *info)
{
	char *temp;

	if (command[ft_strlen(command) + info->cursorshift] == 34)
		info->quote_open = !info->quote_open;
	if (command[ft_strlen(command) + info->cursorshift] == 39)
		info->singlequote_open = !info->singlequote_open;
	temp = ft_strdup(command);
	ft_str_deli(&temp, ft_strlen(temp) + info->cursorshift - 1);
	reprint_row(temp, ft_strlen(temp) + info->cursorshift + 1,
			info->cursorshift);
	return (temp);
}

/*
** Adds a character in the middle of the input. Is called when the user
** inpts a printable and the cursor has been moved from the end of the input.
*/

char	*add_char_to_middle(char *command, t_editor *info, char i)
{
	char *temp;

	if (i == 34)
		info->quote_open = !info->quote_open;
	else if (i == 39)
		info->singlequote_open = !info->singlequote_open;
	temp = ft_str_addi(command, ft_strlen(command) + info->cursorshift, i);
	reprint_row(temp, ft_strlen(temp) + info->cursorshift - 1,
			info->cursorshift);
	return (temp);
}
