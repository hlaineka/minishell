/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:28:09 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:24:25 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Goes through the input on character at a time and updates the screen with
** prosessed output when needed.
*/

/*
** Checks the keypress and calls the right function depending on the input
** ascii 92 = \   ascii 27 = esc   ascii 127 = delete
*/

static int	check_keypress(char c, char **command, t_editor *info)
{
	char	*temp;
	int		n;

	temp = NULL;
	if (c == 127 && (ft_strlen(*command) <= 0) && info->cursorshift == 0)
		temp = ft_strnew(1);
	else if (c == 127 && (ft_strlen(*command) > 0) && info->cursorshift == 0)
		temp = delete_last(*command, info);
	else if (c == 27 && (n = handle_esc(c, *command, &temp)) != 0)
		return (n);
	else if (ft_isprint(c) && info->cursorshift == 0)
		temp = handle_printable(*command, c, info);
	else if (info->cursorshift != 0 && c != 10)
	{
		if (c == 127 && (ft_strlen(*command) + info->cursorshift > 0))
			temp = delete_middle(*command, info);
		else
			temp = add_char_to_middle(*command, info, c);
	}
	else
		temp = ft_strdup(*command);
	ft_free(*command);
	*command = ft_strdup(temp);
	ft_free(temp);
	return (c);
}

/*
** Read one character from standart input and send it to check_keypress()
** function for processing
*/

static int	read_key_press(char **command, t_editor *info)
{
	char	c;
	int		returnable;

	read(STDIN_FILENO, &c, 1);
	returnable = check_keypress(c, command, info);
	return (returnable);
}

/*
** Helper function to lexer(), initializes values of t_editor struct when
** lexer() is called.
*/

static void	lexer_initializer(t_editor *info)
{
	info->quote_open = FALSE;
	info->singlequote_open = FALSE;
	info->cursorshift = 0;
}

/*
** Helper function to lexer(). Processes the arrow presses and call the
** respective functions to update the screen accordingly
*/

static void	check_arrows(int i, t_list **temp_list, char **command,
			t_editor *info)
{
	if (i == UP)
	{
		*temp_list = arrow_up(command, *temp_list);
		info->cursorshift = 0;
	}
	else if (i == DOWN)
		return ;
	else if (i == LEFT)
		arrow_left(info, *command);
	else if (i == RIGHT)
		arrow_right(info);
}

/*
** The main function of lexer. Initializes values and reads through the input
** until it finds newline. Also checks that quotes are not open and waits for
** quotes to be closed before returning to prompt()
*/

char		*lexer(t_editor *info)
{
	char	*command;
	int		i;
	t_list	*temp_list;

	i = 0;
	command = NULL;
	lexer_initializer(info);
	temp_list = info->command_buf;
	while ((i = read_key_press(&command, info)) != 10 || info->quote_open
			|| info->singlequote_open)
	{
		if (i == 10 && (info->quote_open || info->singlequote_open))
		{
			info->cursorshift = 0;
			ft_putstr("\nquote>");
		}
		check_arrows(i, &temp_list, &command, info);
	}
	return (command);
}
