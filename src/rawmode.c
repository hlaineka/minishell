/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rawmode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:04:09 by hlaineka          #+#    #+#             */
/*   Updated: 2021/01/27 15:25:19 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	enable_rawmode(t_editor *info)
{
	struct termios	raw;

	info->original_termios = (struct termios*)malloc(sizeof(struct termios));
	tcgetattr(STDIN_FILENO, info->original_termios);
	tcgetattr(STDIN_FILENO, &raw);
	raw.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);

}

void	disable_rawmode(struct termios *original_termios)
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, original_termios);
}

void	exitprocess(char **argv, t_editor *info)
{
	int		i;
	int		w;
	int		returnable;
	char	returnable_c;

	i = 1;
	w = 0;
	returnable = 0;
	disable_rawmode(info->original_termios);
	while (argv[i] && w < 3 && ft_isdigit(argv[i][w]))
	{
		returnable = (argv[i][w] - '0') + returnable * 10 * (w);
		w++;
	}
	returnable_c = (char)returnable;
	exit ((int)returnable_c);
}

void	check_window_size(t_editor *info)
{
	struct winsize	window_size;

	info->cursorrow = 1;
	info->cursorcol = 1;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &window_size);
	info->screenrows = window_size.ws_row;
	info->screencols = window_size.ws_col;
}