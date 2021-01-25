/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:47:09 by hlaineka          #+#    #+#             */
/*   Updated: 2021/01/25 12:11:18 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		read_string(char *command, char **string, t_editor *info)
{
	int		i;
	char	*temp_str;

	i = 0;
	temp_str = ft_strdup(command);
	while (temp_str[i] != ' ' && temp_str[i] != '\0')
	{
		if (temp_str[i] == '~')
		{
			ft_replace_char(temp_str, i, ft_getenv(info->envp_pointer, "HOME"));
			i = i + ft_strlen(ft_getenv(info->envp_pointer, "HOME")) - 1;
		}
		i++;
	}
	*string = ft_strsub(temp_str, 0, i);
	return(i);
}

void	scanner(char *command, t_editor *info)
{
	char		**one_argv;
	char		*temp_str;
	int			i;
	int			j;//
	t_command	*commands;

	commands = (t_command*)malloc(sizeof(t_command));
	commands->command_argv = NULL;
	commands->next_command = NULL;
	one_argv = (char**)malloc(sizeof(char*));
	one_argv = NULL;
	temp_str = NULL;
	i = 0;
	while (command[i] != '\0')
	{
		if (command[i] == ' ')
			i++;
		else
		{
			ft_printf("-%d-", i);
			i = i + read_string(&command[i], &temp_str, info);
			ft_printf("-%d-", i);
			one_argv = ft_strarr_add(one_argv, temp_str);
			j = 0;
			while (one_argv[j])
			{	
				ft_printf("%d; %s: ", j, one_argv[j]);
				j++;
			}
			ft_free(temp_str);
		}
	}
	ft_printf("here");
	commands->command_argv = one_argv;
	command_execute(commands, info);
}