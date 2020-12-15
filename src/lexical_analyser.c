/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analyser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 13:14:00 by hlaineka          #+#    #+#             */
/*   Updated: 2020/12/01 13:58:32 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		read_program_name(char *command, char **program_name, t_editor *info)
{
	int		i;
	int		w;

	i = 0;
	w = 0;
	
	while (command[i] != ' ' && command[i] != '\0')
	{
		if (command[i] == '~')
		{
			ft_replace_char(command, i, ft_getenv(info->envp_pointer, "HOME"));
			i = i + ft_strlen(ft_getenv(info->envp_pointer, "HOME")) - 1;
		}
		i++;
	}
	*program_name = ft_strsub(command, 0, i);
	return(i);
}

t_command	*lexical_analyser(char *command, t_editor *info)
{
	char		**one_argv;
	char		*temp_command;
	char		*temp_str;
	int			i;
	int			w;
	t_command	*returnable;

	temp_command = ft_strdup(command);
	returnable = (t_command*)malloc(sizeof(t_command));
	returnable->command_argv = NULL;
	returnable->next_command = NULL;
	one_argv = NULL;
	temp_str = NULL;
	i = 0;
	while (temp_command[i])
	{
		i = i + read_program_name(temp_command, &temp_str, info);
		returnable->command_argv = ft_strarr_add(returnable->command_argv, temp_str);
		ft_free(temp_str);
		w = i;
		while (temp_command[i])
		{
			if (temp_command[i] == ' ')
			{
				returnable->command_argv = ft_strarr_add(returnable->command_argv, ft_strsub_mid(temp_command, w, i));
				w = i;
			}
			i++;
		}
	}
	return(returnable);
}