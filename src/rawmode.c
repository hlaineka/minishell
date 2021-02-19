/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rawmode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:04:09 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:24:42 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Starts the shell in rawmode to enable input and output handling by the
** program. Saves the setting of the calling shell to info->original_termios.
*/

void		enable_rawmode(t_editor *info)
{
	struct termios	raw;

	info->original_termios = (struct termios*)malloc(sizeof(struct termios));
	tcgetattr(STDIN_FILENO, info->original_termios);
	tcgetattr(STDIN_FILENO, &raw);
	raw.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

/*
** When the minishell exist, this function is called to reset the settings
** the calling shell had.
*/

void		disable_rawmode(struct termios *original_termios)
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, original_termios);
}

/*
** Checks and saves to info structure the size of the window.
*/

void		check_window_size(t_editor *info)
{
	struct winsize	window_size;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &window_size);
	info->screenrows = window_size.ws_row;
	info->screencols = window_size.ws_col;
}

/*
** Helper function to save_cursor_position(). Read the input string
** giving the location of the cursor.
*/

static int	read_reply(char **buffer)
{
	int		ret;
	char	c;
	int		i;

	i = 0;
	c = 0;
	*buffer = ft_strnew(30);
	while (c != 'R')
	{
		ret = read(0, &c, 1);
		if (!ret || i >= 30)
		{
			ft_printf("%rcursor position reading failed.\n");
			ft_free(buffer);
			return (-1);
		}
		buffer[0][i++] = c;
	}
	if (ft_strlen(*buffer) < 2)
	{
		ft_printf("%rcursor position reading failed.\n");
		ft_free(buffer);
		return (-1);
	}
	return (1);
}

/*
** function uses the value "\033[6n" sent in the std 1 to read the cursor
** position from std 0 in the form of "xxx;yyyy[R". Saves the received value
** to info struct.
*/

int			save_cursor_position(t_editor *info)
{
	char	*buffer;
	int		i;
	int		power;

	ft_putstr("\033[6n");
	if (!read_reply(&buffer))
		return (-1);
	info->cursorcol = 0;
	info->cursorrow = 0;
	i = 0;
	power = 1;
	while (buffer[i] && buffer[i] != ';')
	{
		info->cursorcol = info->cursorcol + (buffer[i++] - '0' * power);
		power = power * 10;
	}
	power = 1;
	while (buffer[i] && buffer[i] != '[')
	{
		info->cursorrow = info->cursorrow + (buffer[i++] - '0' * power);
		power = power * 10;
	}
	ft_free(buffer);
	return (1);
}
