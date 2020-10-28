/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 11:19:46 by hlaineka          #+#    #+#             */
/*   Updated: 2020/10/28 14:25:46 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	add_command(char *command, t_editor *info)
{
	//char	*temp;
	t_list	*new_command;

	//temp = ft_strjoin(command, "\n");
	//ft_lstnewtoend(temp, ft_strlen(temp), &(info->print_buf));
	//add_string_to_cursor(info, temp);
	//print_screen(info, "");
	new_command = ft_lstnew(command, ft_strlen(command));
	ft_lstadd(&(info->command_buf), new_command);
	//free(temp);
}