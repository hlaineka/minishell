/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_reading.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:28:09 by hlaineka          #+#    #+#             */
/*   Updated: 2020/12/17 14:22:12 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_keypress(char c, char **command, t_editor *info)
{
	char	*temp;
	int		n;

	temp = NULL;
	if (c == 10)
		return(c);
	else if (c == 127 && (ft_strlen(*command) <= 0) && info->cursorshift == 0)
		temp = ft_strnew(1);
	else if (c == 127 && (ft_strlen(*command) > 0) && info->cursorshift == 0)
		temp = delete_last(*command, info);
	else if (c == 27 && (n = handle_esc(c, *command, &temp)) != 0)
		return(n);
	else if (ft_isprint(c) && info->cursorshift == 0)
		temp = handle_printable(*command, c, info);
	else
		temp = ft_strdup(*command);
	ft_free(*command);	
	*command = ft_strdup(temp);
	ft_free(temp);
	return(c);
}

int	read_key_press(char **command, t_editor *info)
{
	char	c;
	int		returnable;

	read(STDIN_FILENO, &c, 1);
	returnable = check_keypress(c, command, info);
	return(returnable);
}

char	*lexer(t_editor *info)
{
	char	*command;
	int		i;
	t_list	*temp_list;

	i = 0;
	command = ft_strnew(1);
	info->cursorshift = 0;
	temp_list = info->command_buf;
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
	return (command);
}
