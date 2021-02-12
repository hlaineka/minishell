/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:47:09 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/09 13:02:32 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		read_string(char *command, char **string, t_editor *info)
{
	int		i;
	int		returnable;
	char	*temp_str;
	char	*temp;
	char	*temp2;
	char	*temp3;

	i = 0;
	returnable = 0;
	temp_str = ft_strdup(command);
	//ft_printf("|%s|", temp_str);
	while (temp_str[i] != '\0')
	{
		//ft_printf("-i0-%c-", temp_str[i]);
		if ((temp_str[i] == ' ' || temp_str[i] == '\t') && !info->quote_open && !info->singlequote_open)
			break;
		//else if ((temp_str[i] == ' ' || temp_str[i] == '\t') && (!info->quote_open || !info->singlequote_open))
		//{
		//	temp = ft_str_deli(temp_str, i);
		//	ft_free(temp_str);
		//	temp_str = ft_strdup(temp);
		//	i--;
		//}
		else if (temp_str[i] == 34)
		{
			//ft_printf("-i1-%c-", temp_str[i]);
			info->quote_open = !info->quote_open;
			temp = ft_str_deli(temp_str, i);
			//ft_printf(":%s:", temp);
			ft_free(temp_str);
			temp_str = ft_strdup(temp);
			ft_free(temp);
			//ft_printf("-i2-%c-", temp_str[i]);
			i--;
		}
		else if (temp_str[i] == 39)
		{
			info->singlequote_open = !info->singlequote_open;
			temp = ft_str_deli(temp_str, i);
			ft_free(temp_str);
			temp_str = ft_strdup(temp);
			ft_free(temp);
			i--;
		}
		else if (temp_str[i] == '~')
		{
			if (temp_str[i] && temp_str[i] == '-')
			{
				if (-1 == getenv_index(info->envp_pointer, "OLDPWD"))
				{
					ft_putstr_fd("OLDPWD not set\n", 2);
					return -1;
				}
				temp = ft_getenv(info->envp_pointer, "OLDPWD");
			}
			else if (temp_str[i] && temp_str[i] == '+')
			{
				if (-1 == getenv_index(info->envp_pointer, "PWD"))
				{
					ft_putstr_fd("PWD not set\n", 2);
					return -1;
				}
				temp = ft_getenv(info->envp_pointer, "PWD");
			}
			else
			{
				if (-1 == getenv_index(info->envp_pointer, "HOME"))
				{
					ft_putstr_fd("HOME not set\n", 2);
					return -1;
				}
				temp = ft_getenv(info->envp_pointer, "HOME");
			}
			temp2 = ft_replace_char(temp_str, i, temp);
			i = i + ft_strlen(temp) - 1;
			ft_free(temp);
			free(temp_str);
			temp_str = ft_strdup(temp2);
			free(temp2);
		}
		else if (temp_str[i] == '$')
		{
			read_string(&temp_str[i + 1], &temp3, info);
			temp = ft_getenv(info->envp_pointer, temp3);
			temp2 = ft_strstr_remove(temp_str, temp3);
			returnable = returnable + ft_strlen(temp3) - 1;
			free(temp3);
			temp3 = ft_replace_char(temp2, i, temp);
			i = i + ft_strlen(temp) - 1;
			ft_free(temp);
			free(temp_str);
			temp_str = ft_strdup(temp3);
			free(temp2);
			free(temp3);
		}
		i++;
		returnable++;
	}
	*string = ft_strsub(temp_str, 0, i);
	ft_free(temp_str);
	return(returnable);
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

/*
** ascii 34 = " ascii 39 = '  ascii 92 = \
*/
char	*remove_escchars(char *command)
{
	int		i;
	char	*temp;
	char	*returnable;

	returnable = ft_strdup(command);
	temp = NULL;
	i = 0;
	while (returnable && returnable[i])
	{
		if (returnable[i] == 92)
		{
			temp = ft_str_deli(returnable, i);
			ft_free(returnable);
			returnable = ft_strdup(temp);
			ft_free(temp);
			if (returnable[i])
			{
				if (returnable[i] == 0)
					returnable[i] = '\0';
				if (returnable[i] == 'n')
					returnable[i] = '\n';
				if (returnable[i] == 'r')
					returnable[i] = '\r';
				if (returnable[i] == 't')
					returnable[i] = '\t';
				if (returnable[i] == 'b')
					returnable[i] = '\b';
				if (returnable[i] == 'f')
					returnable[i] = '\f';
				if (returnable[i] == 'v')
					returnable[i] = '\v';
				if (returnable[i] == 'r')
					returnable[i] = '\r';
			}
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
	int			w;
	t_command	*commands;
	char		*temp;

	temp = remove_escchars(command);
	commands = (t_command*)malloc(sizeof(t_command));
	commands->command_argv = NULL;
	commands->next_command = NULL;
	one_argv = NULL;
	temp_str = NULL;
	i = 0;
	while (temp[i] != '\0')
	{
			if (-1 == (w = read_string(&temp[i], &temp_str, info)))
				return;
			i = i + w;
			if (ft_strlen(temp_str) != 0)
				one_argv = ft_strarr_add(one_argv, temp_str);
			ft_free(temp_str);
		if (temp[i] != '\0')
			i++;
	}
	commands->command_argv = one_argv;
	command_execute(commands, info);
	free_commands(commands);
	ft_free(temp);
}