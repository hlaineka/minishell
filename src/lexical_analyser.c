/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analyser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 13:14:00 by hlaineka          #+#    #+#             */
/*   Updated: 2020/11/27 14:18:29 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		read_program_name(char *command, char **program_name, t_editor *info)
{
	int		i;
	int		w;

	i = 0;
	w = 0;
	
	while (command[i] != ' ')
	{
		if (command[i] == '~')
		{
			ft_replace_char(command, i, ft_getenv(info->envp_pointer, "HOME"));
			i = i + ft_strlen(ft_getenv(info->envp_pointer, "HOME"));
		}
	}
	return(i);
}

t_list	*lexical_analyser(char *command, t_editor *info)
{
	t_list	*temp;
	t_list	*returnable;
	char	**one_command;
	char	*temp_command;
	char	*temp_str;
	int		i;

	temp_command = ft_strdup(command);
	i = 0;
	while (temp_command[i])
	{
		i = read_program_name(temp_command, &temp_str, info);
	}
}