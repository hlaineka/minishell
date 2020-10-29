/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 11:53:03 by hlaineka          #+#    #+#             */
/*   Updated: 2020/09/29 14:45:38 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

/*
** The main function that handles printing of the given datastructure
*/

static void		print_all(t_params *params, t_list *first_directory)
{
	t_directory		*temp_directory;
	t_list			*temp_dirlist;

	temp_dirlist = first_directory;
	while (temp_dirlist)
	{
		temp_directory = (t_directory*)temp_dirlist->content;
		if (!temp_directory->stat_info && !ft_strequ(temp_directory->name, ""))
			ft_printf("%s:\n", temp_directory->error_message);
		else
			print_folder(temp_directory, params, first_directory, temp_dirlist);
		temp_dirlist = temp_dirlist->next;
		params->multiple_folders--;
	}
}

/*
** The main function on sorting the data structure. Calls on merge sort
** algorithm with the right comparison functions.
*/

static void		sort_directories(t_list **first_directory, t_params *params)
{
	t_list		*temp_dir_list;
	t_directory	*temp_directory;

	temp_dir_list = *first_directory;
	temp_directory = (t_directory*)temp_dir_list->content;
	if (params->t)
		ft_lst_merge_sort(first_directory, &sort_dir_time);
	else
		ft_lst_merge_sort(first_directory, &sort_dir_name);
	while (temp_dir_list)
	{
		temp_directory = (t_directory*)temp_dir_list->content;
		if (params->t)
			ft_lst_merge_sort(&temp_directory->first_file, &sort_file_time);
		else
			ft_lst_merge_sort(&temp_directory->first_file, &sort_file_name);
		temp_dir_list = temp_dir_list->next;
	}
	if (params->r)
		reverse_lists(first_directory);
}

/*
** Reads the given parameters and calls on read_directory to read
** and save the data
*/

static t_list	*read_argv(int argc, int i, t_params *params, char **argv)
{
	char		*directory_name;
	t_list		*first_directory;

	first_directory = NULL;
	if (i == argc)
	{
		directory_name = ft_strdup(".");
		read_directory(directory_name, params, &first_directory, 1);
		free(directory_name);
	}
	while (argv[i])
	{
		params->multiple_folders++;
		directory_name = ft_strdup(argv[i++]);
		read_directory(directory_name, params, &first_directory, 1);
		free(directory_name);
	}
	return (first_directory);
}

/*
** reads the given input string, and sets params structure values
** accordingly
*/

static void		read_params(char *input, t_params *params)
{
	int		i;

	i = 1;
	while (input[i] != '\0')
	{
		if (input[i] == 'a')
			params->a = 1;
		else if (input[i] == 'l')
			params->l = 1;
		else if (input[i] == 'r')
			params->r = 1;
		else if (input[i] == 'R')
			params->rr = 1;
		else if (input[i] == 't')
			params->t = 1;
		else
		{
			ft_printf("ft_ls: illegal option -- %c\n", input[i]);
			print_usage();
			exit(0);
		}
		i++;
	}
}

/*
** Reads all the params that the program has been given, and adds them
** to relative data structures. Send the list to sorting and printing
** functions and then closes the program.
*/

int				main(int argc, char **argv)
{
	int			i;
	t_params	*params;
	t_list		*first_directory;

	params = (t_params*)malloc(sizeof(t_params));
	initialize_params(params);
	i = 1;
	while (i < argc && argv[i][0] == '-')
		read_params(argv[i++], params);
	first_directory = read_argv(argc, i, params, argv);
	sort_directories(&first_directory, params);
	print_all(params, first_directory);
	return(0);
}
