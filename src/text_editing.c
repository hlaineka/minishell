/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_editing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:11:40 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/01 13:24:14 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*delete_last(char *command)
{
	char	*returnable;

	returnable = NULL;
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

/*
** ascii 39 == '
*/
char	*handle_printable(char *command, char c, t_editor *info)
{
	char	*returnable;

	if (c == '"')
	{
		info->quote_open = !info->quote_open;
		returnable = ft_strdup(command);
	}
	else if (c == 39)
	{	
		info->singlequote_open = !info->singlequote_open;
		returnable = ft_strdup(command);
	}
	else if (c == 10 && !info->quote_open && !info->singlequote_open)
		return (ft_strdup(command));
	else
		returnable = ft_str_char_join(c, command);
	ft_putchar(c);
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
	ft_free(*command);
	*command = ft_strjoin(temp3, temp2);
	reprint_row(*command, ft_strlen(*command) + info->cursorshift + 1, info->cursorshift);
	ft_free(temp);
	ft_free(temp2);
	ft_free(temp3);
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
	ft_free(*command);
	*command = ft_strjoin3(temp, temp3, temp2);
	ft_free(temp);
	ft_free(temp2);
	ft_free(temp3);
	reprint_row(*command, ft_strlen(*command) + info->cursorshift - 1, info->cursorshift);
}