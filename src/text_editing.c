/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_editing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:11:40 by hlaineka          #+#    #+#             */
/*   Updated: 2020/10/28 14:32:55 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*delete_last(char *command, t_editor *info)
{
	char	*returnable;

	returnable = ft_strsub(command, 0, ft_strlen(command) - 1);
	cursor_to_left(info);
	reprint_row(info, returnable);
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

	returnable = ft_str_char_join(c, command);
	//add_char_to_cursor(info, c);
	reprint_row(info, returnable);
	return(returnable);
}

void	delete_middle(char **command, t_editor *info)
{	
	char		*temp;
	char		*temp2;
	char		*temp3;
	
	temp = ft_strsub(*command, 0, ft_strlen(*command) + info->cursorshift);
	temp2 = ft_strsub(*command, ft_strlen(*command) + info->cursorshift, ft_strlen(*command));
	temp3 = ft_strsub(temp, 0, ft_strlen(temp) - 1);
	free(*command);
	*command = ft_strjoin(temp3, temp2);
	//cursor_to_left(info);
	reprint_row(info, *command);
	free(temp);
	free(temp2);
	free(temp3);
}

void	add_char_to_middle(char **command, t_editor *info, char i)
{
	char		*temp;
	char		*temp2;
	char		*temp3;
	
	temp = ft_strsub(*command, 0, ft_strlen(*command) + info->cursorshift);
	temp2 = ft_strsub(*command, ft_strlen(*command) + info->cursorshift, ft_strlen(*command));
	temp3 = (char*)malloc(2);
	temp3[0] = (char)i;
	temp3[1] = '\0';
	free(*command);
	*command = ft_strjoin3(temp, temp3, temp2);
	free(temp);
	free(temp2);
	free(temp3);
	//add_char_to_cursor(info, i);
	reprint_row(info, *command);
}