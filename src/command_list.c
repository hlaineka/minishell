/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 11:19:46 by hlaineka          #+#    #+#             */
/*   Updated: 2020/10/21 11:21:48 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	add_command(char *command, t_editor *info)
{
	char	*temp;
	t_list	*new_command;

	ft_lstnewtoend(command, ft_strlen(command), &(info->print_buf));
	temp = ft_strjoin3("\n", command, "\n");
	print_string(info, temp);
	new_command = ft_lstnew(command, ft_strlen(command));
	ft_lstadd(&(info->command_buf), new_command);
	free(temp);
}