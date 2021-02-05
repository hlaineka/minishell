/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:47:09 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/05 13:22:24 by hlaineka         ###   ########.fr       */
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
	ft_free(temp_str);
	return(i);
}

void	free_commands(t_command *command)
{
	t_command	*next_command;

	while(command)
	{
		next_command = command->next_command;
		ft_strarray_free(command->command_argv);
		ft_free(command);
		command = next_command;
	}
}

char	*remove_quotes(char *command)
{
	int		i;
	char	*temp;
	char	*returnable;

	returnable = ft_strdup(command);
	temp = NULL;
	i = 0;
	while (returnable && returnable[i])
	{
		if (returnable[i] == 34 || returnable[i] == 39)
		{
			temp = ft_str_deli(returnable, i);
			ft_free(returnable);
			returnable = ft_strdup(temp);
			ft_free(temp);
			i--;
		}
		i++;
	}
	return (returnable);
}

void	scanner(char *command, t_editor *info)
{
	char		**one_argv;
	char		*temp_str;
	int			i;
	t_command	*commands;
	char		*temp;

	temp = remove_quotes(command);
	free(command);
	command = ft_strdup(temp);
	free(temp);
	commands = (t_command*)malloc(sizeof(t_command));
	commands->command_argv = NULL;
	commands->next_command = NULL;
	one_argv = NULL;
	temp_str = NULL;
	i = 0;
	while (command[i] != '\0')
	{
		if (command[i] == ' ')
			i++;
		else
		{
			i = i + read_string(&command[i], &temp_str, info);
			one_argv = ft_strarr_add(one_argv, temp_str);
			ft_free(temp_str);
		}
	}
	commands->command_argv = one_argv;
	command_execute(commands, info);
	free_commands(commands);
}