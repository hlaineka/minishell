/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 16:16:25 by hlaineka          #+#    #+#             */
/*   Updated: 2020/09/29 15:23:25 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

/*
** Sorting function given as a parameter to the merge_sort algorithm
** when directories are sorted alphabetically.
*/

int		sort_dir_name(t_list *a, t_list *b)
{
	t_directory	*a_dir;
	t_directory	*b_dir;

	a_dir = (t_directory*)a->content;
	b_dir = (t_directory*)b->content;
	if (ft_strcmp(a_dir->name, b_dir->name) < 0)
		return (TRUE);
	return (FALSE);
}

/*
** Sorting function given as a parameter to the merge_sort algorithm
** when files are sorted alphabetically.
*/

int		sort_file_name(t_list *a, t_list *b)
{
	t_file	*a_file;
	t_file	*b_file;

	a_file = (t_file*)a->content;
	b_file = (t_file*)b->content;
	if (ft_strcmp(a_file->name, b_file->name) < 0)
		return (TRUE);
	return (FALSE);
}

/*
** Sorting function given as a parameter to the merge_sort algorithm
** when directories are sorted by time.
*/

int		sort_dir_time(t_list *a, t_list *b)
{
	t_directory	*a_dir;
	t_directory	*b_dir;

	a_dir = (t_directory*)a->content;
	b_dir = (t_directory*)b->content;
	if (ft_strequ(a_dir->name, ""))
		return (TRUE);
	if (ft_strequ(b_dir->name, ""))
		return (FALSE);
	if (ft_strequ(a_dir->name, "./") || ft_strequ(a_dir->name, "."))
		return (TRUE);
	if (ft_strequ(b_dir->name, "./") || ft_strequ(b_dir->name, "."))
		return (FALSE);
	if ((!a_dir->stat_info || !b_dir->stat_info)
	&& ft_strcmp(a_dir->name, b_dir->name) < 0)
		return (TRUE);
	else
	{
		if (a_dir->stat_info->st_mtime > b_dir->stat_info->st_mtime)
			return (TRUE);
		if ((a_dir->stat_info->st_mtime == b_dir->stat_info->st_mtime)
		&& ft_strcmp(a_dir->name, b_dir->name) < 0)
			return (TRUE);
	}
	return (FALSE);
}

/*
** Sorting function given as a parameter to the merge_sort algorithm
** when files are sorted by time.
*/

int		sort_file_time(t_list *a, t_list *b)
{
	t_file	*a_file;
	t_file	*b_file;

	a_file = (t_file*)a->content;
	b_file = (t_file*)b->content;
	if (!a_file->stat_info || !b_file->stat_info)
		return (FALSE);
	if (a_file->stat_info->st_mtime > b_file->stat_info->st_mtime)
		return (TRUE);
	if (a_file->stat_info->st_mtime == b_file->stat_info->st_mtime)
	{
		if (a_file->stat_info->st_mtimespec.tv_nsec
		> b_file->stat_info->st_mtimespec.tv_nsec)
			return (TRUE);
		if (a_file->stat_info->st_mtimespec.tv_nsec
		== b_file->stat_info->st_mtimespec.tv_nsec
		&& ft_strcmp(a_file->name, b_file->name) < 0)
			return (TRUE);
	}
	return (FALSE);
}

/*
** Function that reverses the given directory list as well as all the
** file lists inside it.
*/

void	reverse_lists(t_list **first_directory)
{
	t_list		*temp_dir_list;
	t_directory	*temp_dir;

	if (!*first_directory)
		return ;
	temp_dir_list = *first_directory;
	temp_dir = (t_directory*)temp_dir_list->content;
	if ((ft_strequ(temp_dir->name, "") || ft_strequ(temp_dir->name, "./"))
		&& temp_dir_list->next)
	{
		temp_dir = (t_directory*)temp_dir_list->next->content;
		if (ft_strequ(temp_dir->name, "") || ft_strequ(temp_dir->name, "./"))
			temp_dir_list = temp_dir_list->next;
		temp_dir_list->next = ft_lst_reverse(&temp_dir_list->next);
	}
	else
		ft_lst_reverse(first_directory);
	temp_dir_list = *first_directory;
	while (temp_dir_list)
	{
		temp_dir = (t_directory*)temp_dir_list->content;
		if (temp_dir->first_file)
			ft_lst_reverse(&temp_dir->first_file);
		temp_dir_list = temp_dir_list->next;
	}
}
