/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 15:45:59 by hlaineka          #+#    #+#             */
/*   Updated: 2020/09/29 14:42:33 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

/*
** Checks the max field width for all the colums when printing with -l
*/

void	check_field_width(struct stat *info, t_directory *directory_info)
{
	if (ft_define_length(info->st_nlink) > directory_info->links_field)
		directory_info->links_field = ft_define_length(info->st_nlink);
	if ((int)ft_strlen(getowner(info)) > directory_info->owner_field)
		directory_info->owner_field = ft_strlen(getowner(info));
	if ((int)ft_strlen(getgroup(info)) > directory_info->group_field)
		directory_info->group_field = ft_strlen(getgroup(info));
	if (ft_define_length(info->st_size) > directory_info->size_field)
		directory_info->size_field = ft_define_length(info->st_size);
	directory_info->total = directory_info->total + info->st_blocks;
}

/*
** Gets sticky bits (and some xattributes, but this is still buggy)
*/

char	*get_sattr(struct stat *buffer, char *filename, char *directory,
		char *returnable)
{
	char	*name_buf;
	char	*path_name;

	name_buf = NULL;
	path_name = ft_strjoin(directory, filename);
	returnable[10] = listxattr(path_name, name_buf, 0, 0) > 0 ? '@' : ' ';
	if (buffer->st_mode & S_ISUID)
		returnable[3] = (buffer->st_mode & S_IXUSR) ? 's' : 'S';
	if (buffer->st_mode & S_ISGID)
		returnable[6] = (buffer->st_mode & S_IXGRP) ? 's' : 'S';
	if (buffer->st_mode & S_ISVTX)
		returnable[9] = (buffer->st_mode & S_IXOTH) ? 't' : 'T';
	free(path_name);
	return (returnable);
}

/*
** returns as a character the filetype of given stat struct
*/

char	get_filetype(struct stat *buffer)
{
	char	c;

	if (S_ISREG(buffer->st_mode))
		c = '-';
	else if (S_ISDIR(buffer->st_mode))
		c = 'd';
	else if (S_ISBLK(buffer->st_mode))
		c = 'b';
	else if (S_ISCHR(buffer->st_mode))
		c = 'c';
	else if (S_ISFIFO(buffer->st_mode))
		c = 'p';
	else if (S_ISLNK(buffer->st_mode))
		c = 'l';
	else if (S_ISSOCK(buffer->st_mode))
		c = 's';
	else
		c = '?';
	return (c);
}

/*
** returns as a string the owner of the stat struct given as parameter.
** if the username cannot be found, returns the id number as a string
*/

char	*getowner(struct stat *buffer)
{
	struct passwd	*user_info;

	if ((user_info = getpwuid(buffer->st_uid)))
		return (user_info->pw_name);
	else
		return (ft_itoa(buffer->st_uid));
}

/*
** returns as a string the group of the stat struct given as parameter.
** if the group cannot be found, returns the id number as a string
*/

char	*getgroup(struct stat *buffer)
{
	struct group	*group_info;

	if ((group_info = getgrgid(buffer->st_gid)))
		return (group_info->gr_name);
	else
		return (ft_itoa(buffer->st_gid));
}
