/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 13:54:45 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/12 15:11:25 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "../libft/includes/ft_printf.h"
#include "../libft/includes/libft.h"
#include <termios.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdbool.h>
# define UP 279165
# define LEFT 279168
# define RIGHT 279167
# define DOWN 279166
# define ESC 27
int		g_errnbr;

typedef struct		s_editor
{
	struct termios	*original_termios;
	t_list			*command_buf;
	t_list			*print_buf;
	int				screenrows;
	int				screencols;
	int				cursorrow;
	int				cursorcol;
	int				cursorshift;
	char			**envp_pointer;
	bool			quote_open;
	bool			singlequote_open;
}					t_editor;

typedef struct		s_command
{
	char				**command_argv;
	struct s_command	*next_command;
}					t_command;


/*
** rawmode.c
*/
void	enable_rawmode(t_editor *info);
void	disable_rawmode(struct termios *original_termios);
void	check_window_size(t_editor *info);

/*
** cursor_move.c
*/
void	add_string_to_cursor(t_editor *info, char *printable);
void	remove_string_from_cursor(t_editor *info, char *printable);
void	add_char_to_cursor(t_editor *info, char c);

/*
** screen_printing.c
*/
void	clear_screen();
void	print_info();
void	print_bitwise();
void	reprint_row(char *command, int lenght, int cursorshift);

/*
** text_editing.c
*/
char	*delete_last(char *command, t_editor *info);
int		handle_esc(char c, char *command, char **temp);
char	*handle_printable(char *command, char c, t_editor *info);
void	delete_middle(char **command, t_editor *info);
void	add_char_to_middle(char **command, t_editor *info, char i);

/*
** lexer.c
*/
char	*lexer(t_editor *info);
int		read_key_press(char **command, t_editor *info);
int		check_keypress(char c, char **command, t_editor *info);

/*
** arrows.c
*/
t_list	*arrow_up(char **command, t_list *command_list);
void	arrow_left(t_editor *info, char *command);
void	arrow_right(t_editor *info);

/*
** command_list.c
*/
void	add_command(char *command, t_editor *info);

/*
** env.c
*/
void	ft_env(char **argv, t_editor *info, char **envp);

/*
** setenv.c
*/
void	ft_setenv(char **argv,  t_editor *info);
int		getenv_index(char **envp_pointer, char *name);
char	**add_str_to_env(char **envp, char *new_value, int i);

/*
** scanner.c
*/
void	scanner(char *command, t_editor *info);
int		check_executable(t_editor *info, char *executable, char **path_executable);

/*
** unsetenv.c
*/
void	ft_unsetenv(char **argv, t_editor *info);
char	**ft_envhelper_unset(char* str, char **envp);

/*
**	cd.c
*/
int		ft_cd(char **argv, t_editor *info);

/*
** command_execute.c
*/
void	command_execute(t_command *command, t_editor *info);
int		check_executable(t_editor *info, char *executable, char **path_executable);
int		check_buildins(t_editor *info, char** temp_argv, char **envp);

/*
** echo.c
*/
void	ft_echo(char **argv);

/*
** pwd.c
*/
void	ft_pwd(char **envp);
char	*get_pwd(char **envp);

/*
** errors.c
*/
int		print_errorstr(int errnbr, char *caller, char *path);

/*
** exit.c
*/
void	exitprocess(char **argv, t_editor *info);

#endif