/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 13:37:18 by hlaineka          #+#    #+#             */
/*   Updated: 2020/10/05 14:38:40 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	enable_rawmode(struct t_info *info)
{
	struct termios	*raw;
	struct termios	*original_termios;

	original_termios = (struct termios*)malloc(sizeof(struct termios));
	tcgetattr(STDIN_FILENO, original_termios);
	info->orginal_termios = original_termios;
	tcgetattr(STDIN_FILENO, raw);
	(*raw).c_lflag &= ~(ECHO | ICANON);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, raw);
}

void	disable_rawmode(struct termios original_termios)
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &original_termios);
}

void	exitprocess(struct t_info *info)
{
	disable_rawmode(info->original_termios);
	exit (0);
}

char	read_key_press(struct t_info *info)
{
	char	returnable;

	while (read(STDIN_FILENO, &returnable, 1) == 1)
	{
		if (ft_iscntrl(returnable))
			ft_printf("%d", returnable);
		else
			ft_printf("%c", returnable);
		if (returnable == 'q')
			exitprocess(info);
	}
	return(returnable);
}

void	process_key_press(struct t_info *info)
{
	char	c;

	c = read_key_press(info);
}

int		main(void)
{
	struct t_allinfo	*info;
	
	enable_rawmode(info);
	process_key_press(info);
}