/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 13:54:45 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/15 20:10:02 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"
# include <termios.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <stdbool.h>
# define UP 279165
# define LEFT 279168
# define RIGHT 279167
# define DOWN 279166
# define ESC 27

int	g_errnbr;

typedef struct			s_editor
{
	struct termios		*original_termios;
	t_list				*command_buf;
	t_list				*print_buf;
	int					screenrows;
	int					screencols;
	int					cursorrow;
	int					cursorcol;
	int					cursorshift;
	char				**envp_pointer;
	bool				quote_open;
	bool				singlequote_open;
}						t_editor;

typedef struct			s_command
{
	char				**command_argv;
	struct s_command	*next_command;
}						t_command;

/*
** rawmode.c
*/

void					enable_rawmode(t_editor *info);
void					disable_rawmode(struct termios *original_termios);
void					check_window_size(t_editor *info);
int						save_cursor_position(t_editor *info);

/*
** screen_printing.c
*/

void					clear_screen();
int						print_info();
void					reprint_row(char *command, int lenght, int cursorshift);

/*
** text_editing.c
*/

char					*delete_last(char *command, t_editor *info);
int						handle_esc(char c, char *command, char **temp);
char					*handle_printable(char *command, char c,
						t_editor *info);
char					*delete_middle(char *command, t_editor *info);
char					*add_char_to_middle(char *command, t_editor *info,
						char i);

/*
** lexer.c
*/

char					*lexer(t_editor *info);

/*
** arrows.c
*/

t_list					*arrow_up(char **command, t_list *command_list);
void					arrow_left(t_editor *info, char *command);
void					arrow_right(t_editor *info);

/*
** command_list.c
*/

void					add_command(char *command, t_editor *info);

/*
** env.c
*/

int						ft_env(char **argv, t_editor *info, char **envp);
int						print_envusage(int error, char c);
int						print_env(char **temp_envp);

/*
** env_helpers.c
*/

int						handle_env_parameter(char **argv, int *i,
						char ***temp_envp);
int						handle_new_env(char **argv, int i, char ***temp_envp);
int						env_command_nf(char **temp_envp, char **temp_argv);
int						env_free(char **temp_envp, char **temp_argv);

/*
** setenv.c
*/

int						ft_setenv(char **argv, char ***envp);
int						getenv_index(char **envp_pointer, char *name);
char					**add_str_to_env(char **envp, char *new_value, int i);

/*
** scanner.c
*/

void					scanner(char *command, t_editor *info);
int						read_string(char *command, char **string,
						t_editor *info);

/*
** scanner_helpers.c
*/

int						replace_tilde(char **temp_str, int *i, t_editor *info);
int						replace_dollar(char **temp_str, int *i, t_editor *info);
int						replace_escchar(int c);
void					free_commands(t_command *command);

/*
** scanner_helpers2.c
*/

char					*replacer(char *orig, char *env_str, int *i,
						t_editor *info);

/*
** unsetenv.c
*/

int						ft_unsetenv(char **argv, char ***envp);
char					**ft_envhelper_unset(char *str, char **envp);

/*
**	cd.c
*/

int						ft_cd(char **argv, char ***envp);

/*
**	cd_helpers.c
*/

char					*get_cd_path(char *path, char **envp);
int						add_cdpath_env(char *path, char ***envp);
int						cd_errorfree(char *message, char *tofree);

/*
** command_execute.c
*/

void					command_execute(t_command *command, t_editor *info);
int						check_executable(char **envp, char *executable,
						char **path_executable);
int						check_buildins(t_editor *info, char **temp_argv,
						char ***envp);

/*
** echo.c
*/

int						ft_echo(char **argv);

/*
** pwd.c
*/

int						ft_pwd(char **envp);
char					*get_pwd(char **envp);

/*
** errors.c
*/

int						print_errorstr(int errnbr, char *caller, char *path);
void					errstrs(char *str1, char *str2);

/*
** exit.c
*/

void					exitprocess(char **argv, t_editor *info);

#endif
