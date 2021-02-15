/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:47:09 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/15 16:24:51 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
** The scanner function goes through the argument string and makes an argv
** argument of it. Scanner also substitutes special character, like ~ (tilde)
** $ (dollar) and esc characters like \n.
*/

/*
** check_replacement finds out if there are special character ~ or $ and
** substitutes corresponding values to the argument. Also checks for strings
** and allows the minishell to read quotet strings as one argv argument.
** ascii 34 = " ascii 39 = '
*/

static int		check_replacement(char **temp_str, t_editor *info, int *i,
				int *returnable)
{
	if (temp_str[0][*i] == 34)
	{
		info->quote_open = !info->quote_open;
		ft_str_deli(temp_str, *i--);
	}
	else if (temp_str[0][*i] == 39)
	{
		info->singlequote_open = !info->singlequote_open;
		ft_str_deli(temp_str, *i--);
	}
	else if (*i == 0 && temp_str[0][*i] == '~')
	{
		if (-1 == replace_tilde(temp_str, i, info))
			return (-1);
	}
	else if (temp_str[0][*i] == '$' && temp_str[0][*i + 1] != ' '
			&& temp_str[0][*i + 1] != '\0')
	{
		*returnable = *returnable + replace_dollar(temp_str, i, info);
	}
	return (0);
}

/*
** Function responsible for going through the string until it finds a space
** character (with quotes closed) of '\0'. Calls check_replacement to
** substitute special character (others than esc chars)
*/

int				read_string(char *command, char **string, t_editor *info)
{
	int		i;
	int		returnable;
	char	*temp_str;

	i = 0;
	returnable = 0;
	temp_str = ft_strdup(command);
	while (temp_str[i] != '\0')
	{
		if (temp_str[i] == ' ' && !info->quote_open && !info->singlequote_open)
			break ;
		if (-1 == (check_replacement(&temp_str, info, &i, &returnable)))
			return (-1);
		i++;
		returnable++;
	}
	*string = ft_strsub(temp_str, 0, i);
	ft_free(temp_str);
	return (returnable);
}

/*
** Goes through the whole string and replaces special esc characters pairs
** like \n from the string and substitutes them with the right value.
** ascii 92 = \
*/

char			*remove_escchars(char *command)
{
	int		i;
	char	*returnable;

	returnable = ft_strdup(command);
	i = 0;
	while (returnable && returnable[i])
	{
		if (returnable[i] == 92)
		{
			ft_str_deli(&returnable, i);
			if (returnable[i])
				returnable[i] = replace_escchar(returnable[i]);
		}
		i++;
	}
	return (returnable);
}

/*
** Helper function to make scanner() shorter. Goes through the string (with
** esc chars already substituted) and add every separate argument to the
** argv argument.
*/

static int		string_scanner(char *temp, t_editor *info, t_command *commands)
{
	char		**one_argv;
	int			i;
	int			w;
	char		*temp_str;

	one_argv = NULL;
	temp_str = NULL;
	i = 0;
	while (temp[i] != '\0')
	{
		if (-1 == (w = read_string(&temp[i], &temp_str, info)))
		{
			ft_free(temp);
			ft_strarray_free(one_argv);
			return (0);
		}
		i = i + w;
		if (ft_strlen(temp_str) != 0)
			one_argv = ft_strarr_add(one_argv, temp_str);
		ft_free(temp_str);
		if (temp[i] != '\0')
			i++;
	}
	commands->command_argv = one_argv;
	return (1);
}

/*
** Scanner is responsible for substitutions and creating the argv argument.
*/

void			scanner(char *command, t_editor *info)
{
	t_command	*commands;
	char		*temp;

	temp = remove_escchars(command);
	commands = (t_command*)malloc(sizeof(t_command));
	commands->command_argv = NULL;
	commands->next_command = NULL;
	if (!string_scanner(temp, info, commands))
	{
		free_commands(commands);
		return ;
	}
	command_execute(commands, info);
	free_commands(commands);
	ft_free(temp);
}
