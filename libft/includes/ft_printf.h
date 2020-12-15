/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 12:23:22 by hlaineka          #+#    #+#             */
/*   Updated: 2020/12/01 16:50:01 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include "libft.h"

/*
** Text color definitions
*/
# define BLACK				"\033[0;30m"
# define RED 				"\033[0;31m"
# define GREEN 				"\033[0;32m"
# define YELLOW 			"\033[0;33m"
# define BLUE				"\033[0;34m"
# define MAGENTA			"\033[0;35m"
# define CYAN 				"\033[0;36m"
# define WHITE 				"\033[0;37m"
# define BRIGHT_BLACK 		"\033[30;1m"
# define BRIGHT_RED 		"\033[31;1m"
# define BRIGHT_GREEN		"\033[32;1m"
# define BRIGHT_YELLOW		"\033[33;1m"
# define BRIGHT_BLUE		"\033[34;1m"
# define BRIGHT_MAGENTA		"\033[35;1m"
# define BRIGHT_CYAN		"\033[36;1m"
# define BRIGHT_WHITE		"\033[37;1m"
# define RESET				"\033[0m"

/*
** Backgroud color definitions
*/
# define BG_BLACK 			"\033[40m"
# define BG_RED				"\033[41m"
# define BG_GREEN			"\033[42m"
# define BG_YELLOW			"\033[43m"
# define BG_BLUE			"\033[44m"
# define BG_MAGENTA			"\033[45m"
# define BG_CYAN			"\033[46m"
# define BG_WHITE			"\033[47m"
# define BG_BRIGHT_BLACK	"\033[40;1m"
# define BG_BRIGHT_RED		"\033[41;1m"
# define BG_BRIGHT_GREEN	"\033[42;1m"
# define BG_BRIGHT_YELLOW	"\033[43;1m"
# define BG_BRIGHT_BLUE		"\033[44;1m"
# define BG_BRIGHT_MAGENTA	"\033[45;1m"
# define BG_BRIGHT_CYAN		"\033[46;1m"
# define BG_BRIGHT_WHITE	"\033[47;1m"

/*
** Decorations definitions
*/
# define BOLD				"\033[1m"
# define UNDERLINE			"\033[4m"
# define REVERSED			"\033[7m"

/*
** A struct to save all the data about a command
*/
typedef struct	s_tags
{
	char		specifier;
	int			positive_value;
	int			flag_zero;
	int			flag_minus;
	int			flag_plus;
	int			flag_space;
	int			flag_hash;
	int			flag_fd;
	int			width;
	int			width_address;
	int			precision;
	int			precision_address;
	int			length;
	int			length_hh;
	int			length_h;
	int			length_l;
	int			length_ll;
	int			length_lll;
	int			empty;
}				t_tags;

/*
** The main function to handle printing
*/

int				ft_printf(const char *format, ...);

/*
** Helper functions to set command values
*/
void			set_flag(t_tags *command, char flag);
void			set_width(t_tags *command, char c, va_list *source);
void			set_precision(t_tags *command, char c, va_list *source);
void			set_length(t_tags *command, char c);
void			set_wildcard_precision(t_tags *command, va_list *source);

/*
** The fuctions called by selector on ft_printf, main functions
** to handle different data types.
*/
int				print_s(t_tags *command, va_list *source);
int				print_c(t_tags *command, va_list *source);
int				print_p(t_tags *command, va_list *source);
int				print_d(t_tags *command, va_list *source);
int				print_o(t_tags *command, va_list *source);
int				print_u(t_tags *command, va_list *source);
int				print_x(t_tags *command, va_list *source);
int				print_f(t_tags *command, va_list *source);

/*
** Helper functions
*/
uintmax_t		read_octal(t_tags *command, va_list *source);
long long int	read_int(t_tags *command, va_list *source);
long double		read_float(t_tags *command, va_list *source);
uintmax_t		read_hexa(t_tags *command, va_list *source);
void			int_width_flag_zero(char *returnable, char *string,
					t_tags *command);
void			float_width_flag_zero(char *returnable, char *string,
					t_tags *command);
void			uint_width_flag_zero(char *returnable, char *string,
					t_tags *command);
char			*ft_trim(char *str, t_tags *command);
long double		ft_round(long double number, t_tags *command);
char			*hexa_upperalpha(char *string);
int				is_specifier(char c);

#endif
