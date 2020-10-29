/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_dirlist3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 20:42:00 by hlaineka          #+#    #+#             */
/*   Updated: 2020/09/23 20:42:10 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

/*
** Adds a file to the last directory of the list.
*/

void	add_file(t_file *new_file, t_params *params, t_list *first_directory)
{
	t_list		*directory_elem;
	t_directory	*temp_directory;
	struct stat	*temp_stat;

	directory_elem = ft_lstend(first_directory);
	temp_directory = (t_directory*)directory_elem->content;
	temp_stat = (struct stat*)new_file->stat_info;
	if (params->l && temp_stat)
		check_field_width(temp_stat, temp_directory);
	ft_lstnewtoend(new_file, sizeof(t_file), &(temp_directory->first_file));
}
