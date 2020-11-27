/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_reading.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:28:09 by hlaineka          #+#    #+#             */
/*   Updated: 2020/11/26 17:11:46 by hlaineka         ###   ########.fr       */
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