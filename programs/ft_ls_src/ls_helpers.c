/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 15:25:02 by hlaineka          #+#    #+#             */
/*   Updated: 2020/09/29 12:43:41 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

/*
** Initializes the directory struct.
*/

void	initialize_directory(t_directory *directory)
{
	directory->total = 0;
	directory->links_field = 0;
	directory->owner_field = 0;
	directory->group_field = 0;
	directory->size_field = 0;
	directory->first_file = NULL;
	directory->stat_info = NULL;
	directory->error_message = NULL;
}

/*
** Prints usage of the program in case of false flags input.
*/

void	print_usage(void)
{
	ft_printf("usage: ft_ls [-alrRt] [file ...]\n");
}

/*
** Initializes the params structure
*/

void	initialize_params(t_params *params)
{
	params->a = 0;
	params->l = 0;
	params->r = 0;
	params->rr = 0;
	params->t = 0;
	params->multiple_folders = -1;
	return ;
}

/*
** Creates and saves an error message when ever a error is found while
** reading a file. Saves the error in the error_message of the file, as
** well as other info accordingly. Stat struct is always set as NULL
** whenever there was an error reading the file.
*/

void	handle_file_error(char *file_name, t_params *params,
		t_list **first_directory)
{
	t_file	*new_file;
	char	*error_message;
	char	*error_str;
	char	*temp;

	error_message = ft_strjoin("ft_ls: ", file_name);
	error_message = ft_strjoin_frees1(error_message, ": ");
	error_str = ft_strdup(strerror(errno));
	error_message = ft_strjoin_frees1(error_message, error_str);
	temp = NULL;
	if (ft_strlast(error_message) == ':')
	{
		temp = ft_strsub(file_name, 0, ft_strlen(file_name) - 1);
		free(error_message);
		error_message = ft_strdup(temp);
	}
	new_file = (t_file*)malloc(sizeof(t_file));
	new_file->error_message = ft_strdup(error_message);
	new_file->name = ft_strdup(file_name);
	new_file->is_link = FALSE;
	new_file->stat_info = NULL;
	add_file(new_file, params, *first_directory);
	free(error_message);
	free(error_str);
	free(temp);
}

/*
** Creates and saves an error message when ever a error is found while
** reading a folder. Saves the error in the error_message of the folder, as
** well as other info accordingly. Stat struct is always set as NULL
** whenever there was an error reading the folder.
*/

void	handle_dir_error(char *directory_name, t_list **first_directory)
{
	char		*error_message;
	t_directory	*new_directory;
	char		*error_str;

	error_message = ft_strjoin("ft_ls: ", directory_name);
	error_message = ft_strjoin_frees1(error_message, ": ");
	error_str = ft_strdup(strerror(errno));
	error_message = ft_strjoin_frees1(error_message, error_str);
	new_directory = (t_directory*)malloc(sizeof(t_directory));
	initialize_directory(new_directory);
	new_directory->name = ft_strdup(directory_name);
	new_directory->stat_info = NULL;
	new_directory->error_message = ft_strdup(error_message);
	ft_lstnewtoend(new_directory, sizeof(t_directory), first_directory);
	free(error_message);
	free(error_str);
	free(new_directory);
}
