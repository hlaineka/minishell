/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 13:54:45 by hlaineka          #+#    #+#             */
/*   Updated: 2020/10/31 16:09:56 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "../libft/includes/ft_printf.h"
#include "../libft/includes/libft.h"
#include "../programs/ft_ls_src/includes/ft_ls.h"
#include <termios.h>
#include <sys/ioctl.h>
# define UP 279165
# define LEFT 279168
# define RIGHT 279167
# define DOWN 279166
# define ESC 27

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
}					t_editor;

typedef struct		s_string
{
	char	*string;
	int		len;
}					t_string;

/*
** rawmode.c
*/
void	enable_rawmode(t_editor *info);
void	disable_rawmode(struct termios *original_termios);
void	exitprocess(t_editor *info);
void	check_window_size(t_editor *info);

/*
** cursor_move.c
*/
void	add_string_to_cursor(t_editor *info, char *printable);
void	remove_string_from_cursor(t_editor *info, char *printable);
void	add_char_to_cursor(t_editor *info, char c);
void	cursor_to_left(t_editor *info);

/*
** screen_printing.c
*/
void	clear_screen();
void	print_info();
void	print_bitwise();
void	reprint_row(t_editor *info, char *command);

/*
** text_editing.c
*/
char	*delete_last(char *command, t_editor *info);
int		handle_esc(char c, char *command, char **temp);
char	*handle_printable(char *command, char c, t_editor *info);
void	delete_middle(char **command, t_editor *info);
void	add_char_to_middle(char **command, t_editor *info, char i);

/*
** key_press_reading.c
*/
int		read_key_press(char **command, t_editor *info);
int		check_keypress(char c, char **command, t_editor *info);

/*
** arrows.c
*/
t_list	*arrow_up(char **command, t_editor *info, t_list *command_list);
void	arrow_left(t_editor *info, char *command);
void	arrow_right(t_editor *info, char *command);

/*
** command_list.c
*/
void	add_command(char *command, t_editor *info);

/*
** env.c
*/
void	print_env(t_editor *info);

/*
** setenv.c
*/
void	ft_setenv(char **argv, char **envp);

/*
** command_check.c
*/
void	check_command(char *command, t_editor *info);
int		check_executable(t_editor *info, char *executable, char **path_executable);

#endif