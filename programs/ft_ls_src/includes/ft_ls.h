/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 16:15:23 by hlaineka          #+#    #+#             */
/*   Updated: 2020/10/05 14:33:46 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../../../libft/includes/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <sys/xattr.h>
# include <errno.h>

/*
** Data structure:
** All the data read in saved in one linked list. The basic node of the
** list is dedefined in libft.h and is as follows:
** typedef struct		s_list
**
**{
**	void			*content;
**	size_t			content_size;
**	struct s_list	*next;
**
**}					t_list;
**
** On the content is saved every directory to be printed. In the
** t_directory struct important data of the directory is saved: number
** of total blocks in total, maximum width of links, owner, size and group
** colums when printing with -l as well as the name of the folder, stat
** struct and possible error message generated while reading the directory.
** All the folders  are saved in a linked list as above on the first_file.
*/

typedef struct	s_directory
{
	int			total;
	int			links_field;
	int			owner_field;
	int			group_field;
	int			size_field;
	t_list		*first_file;
	char		*name;
	struct stat	*stat_info;
	char		*error_message;
}				t_directory;

/*
** Info about every file is saved in t_file struct, that is the name of
** the file, stat struct, info if it is a directory or a link as well as
** the possible error message generated while reading the file.
*/

typedef struct	s_file
{
	char		*name;
	char		*link_name;
	int			is_link;
	struct stat	*stat_info;
	int			is_dir;
	char		*error_message;

}				t_file;

/*
** The params given to the program are saved in the t_params struct.
** The Struct contains info on flags, and info if there is several
** files/folders given as a parameter.
*/

typedef struct	s_params
{
	int			a;
	int			l;
	int			rr;
	int			r;
	int			t;
	int			multiple_folders;
}				t_params;

/*
** Functions used to read directory stream and creating the data structure for
** saving the info. Found in ls_dirlist.c, ls_dirlist2.c and ls_dirlist3.c
*/

void			read_directory(char	*directory_name, t_params *params,
				t_list **first_directory, int caller);
void			add_directory(char *directory_name, t_list **first_directory,
				struct stat *stat_buf);
void			add_file(t_file *new_file, t_params *params,
				t_list *first_directory);
void			add_to_list(struct dirent *dirent_buf, struct stat *stat_buf,
				t_params *params, t_list **first_directory);
void			read_link(char *file_name, t_file *new_file);
void			find_dir_add_file(t_list **first_directory, t_file *new_file,
				t_params *params);
int				handle_file_param(char *file_name, t_list **first_directory,
				t_params *params);

/*
** Helper functions to sorting the files and folders. Found in ls_sort.c
*/

int				sort_dir_name(t_list *a, t_list *b);
int				sort_dir_time(t_list *a, t_list *b);
int				sort_file_name(t_list *a, t_list *b);
int				sort_file_time(t_list *a, t_list *b);
void			reverse_lists(t_list **first_directory);

/*
** Print helpers. Found in ls_print.c and ls_print_helpers.c
*/
void			print_folder(t_directory *printable, t_params *params,
				t_list *first_directory, t_list *printable_dir_list);
char			*getowner(struct stat *buffer);
char			*getgroup(struct stat *buffer);
char			get_filetype(struct stat *buffer);
char			*get_sattr(struct stat *buffer, char *filename, char *directory,
				char *returnable);
void			check_field_width(struct stat *info,
				t_directory *directory_info);
void			check_field_width(struct stat *info,
				t_directory *directory_info);

/*
** Helper functions to initialize or to handle errors. Found in ls_helpers.c
*/

void			initialize_directory(t_directory *directory);
void			print_usage(void);
void			initialize_params(t_params *params);
void			handle_file_error(char *file_name, t_params *params,
				t_list **first_directory);
void			handle_dir_error(char *directory_name,
				t_list **first_directory);
char			*check_name(char *name);

#endif
