/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 16:13:13 by hlaineka          #+#    #+#             */
/*   Updated: 2020/09/29 14:43:23 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

/*
** creates and returns a string where all the modes are marked
*/

static char	*get_modes(struct stat *buffer, char *filename, char *directory,
			int is_link)
{
	char	*returnable;

	returnable = ft_strset('-', 11);
	returnable[0] = get_filetype(buffer);
	if (is_link)
		returnable[0] = 'l';
	if (buffer->st_mode & S_IRUSR)
		returnable[1] = 'r';
	if (buffer->st_mode & S_IWUSR)
		returnable[2] = 'w';
	if (buffer->st_mode & S_IXUSR)
		returnable[3] = 'x';
	if (buffer->st_mode & S_IRGRP)
		returnable[4] = 'r';
	if (buffer->st_mode & S_IWGRP)
		returnable[5] = 'w';
	if (buffer->st_mode & S_IXGRP)
		returnable[6] = 'x';
	if (buffer->st_mode & S_IROTH)
		returnable[7] = 'r';
	if (buffer->st_mode & S_IWOTH)
		returnable[8] = 'w';
	if (buffer->st_mode & S_IXOTH)
		returnable[9] = 'x';
	return (get_sattr(buffer, filename, directory, returnable));
}

/*
** returns a string with a printable timestamp
*/

static char	*gettime(struct stat *buffer)
{
	time_t	timestamp;
	char	*returnable;
	char	*year_now;
	time_t	seconds;
	char	*temp_year;

	seconds = time(NULL);
	year_now = ft_strdup(ctime(&seconds));
	year_now = ft_str_realloc(year_now, 19, 5);
	timestamp = buffer->st_mtime;
	returnable = ft_strdup(ctime(&timestamp));
	temp_year = ft_strsub(returnable, 19, 5);
	if (seconds - timestamp < 15778800)
		returnable = ft_str_realloc(returnable, 4, 12);
	else
	{
		returnable = ft_str_realloc(returnable, 4, 7);
		returnable = ft_strjoin_frees1(returnable, temp_year);
	}
	free(temp_year);
	free(year_now);
	return (returnable);
}

/*
** prints one line of info (= that of one file) when parameter -l is given
*/

static void	print_l(char *file_name, struct stat *buffer,
				t_directory *directory, int is_link)
{
	char	*temp;

	temp = get_modes(buffer, file_name, directory->name, is_link);
	ft_printf("%s ", temp);
	free(temp);
	ft_printf("%*d ", directory->links_field, buffer->st_nlink);
	ft_printf("%-*s  ", directory->owner_field, getowner(buffer));
	ft_printf("%-*s  ", directory->group_field, getgroup(buffer));
	ft_printf("%*d ", directory->size_field, buffer->st_size);
	temp = gettime(buffer);
	ft_printf("%s ", temp);
	free(temp);
	ft_printf("%s\n", file_name);
	return ;
}

/*
** Prints the list of files in a folder
*/

static void	print_filelist(t_params *params, t_directory *directory)
{
	t_file	*temp_file;
	t_list	*temp_list;
	char	*temp_pathname;

	temp_list = directory->first_file;
	while (temp_list)
	{
		temp_file = (t_file*)temp_list->content;
		if (!ft_strequ(directory->name, ""))
			temp_pathname = ft_strjoin(directory->name, temp_file->name);
		else
			temp_pathname = ft_strdup(temp_file->name);
		read_link(temp_pathname, temp_file);
		free(temp_pathname);
		if (params->l && temp_file->stat_info)
			print_l(temp_file->link_name, temp_file->stat_info, directory,
			temp_file->is_link);
		else
			ft_printf("%s\n", temp_file->name);
		temp_list = temp_list->next;
	}
}

/*
** prints all the info needed of a folder. Takes in to consideration all the
** flags given
*/

void		print_folder(t_directory *printable, t_params *params,
			t_list *first_directory, t_list *printable_dir_list)
{
	char			*directory_name;

	if (!ft_strequ(printable->name, ""))
		directory_name = ft_strsub(printable->name, 0,
		ft_strlen(printable->name) - 1);
	if ((params->rr || (params->multiple_folders > -1)) && printable_dir_list
	!= first_directory)
		ft_printf("%s:\n", directory_name);
	if (params->l && !ft_strequ(printable->name, "")
	&& printable->first_file)
		ft_printf("total %d\n", printable->total);
	print_filelist(params, printable);
	if ((params->rr && printable_dir_list->next) || printable_dir_list->next)
		ft_printf("\n");
	if (!ft_strequ(printable->name, "") && printable->stat_info)
		free(directory_name);
}
