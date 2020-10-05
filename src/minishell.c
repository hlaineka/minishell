/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 13:37:18 by hlaineka          #+#    #+#             */
/*   Updated: 2020/10/05 15:07:44 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	enable_rawmode(t_info *info)
{
	struct termios	*raw;
	struct termios	*original_termios;

	raw = NULL;
	original_termios = NULL;
	tcgetattr(STDIN_FILENO, original_termios);
	//ft_memcpy(original_termios, raw, sizeof(struct termios));
	info->original_termios = original_termios;
	ft_printf("asdf");
	tcgetattr(STDIN_FILENO, raw);
	(*raw).c_lflag &= ~(ECHO | ICANON);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, raw);
}

void	disable_rawmode(struct termios *original_termios)
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, original_termios);
}

void	exitprocess(t_info *info)
{
	disable_rawmode(info->original_termios);
	exit (0);
}

char	read_key_press(t_info *info)
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

void	process_key_press(t_info *info)
{
	char	c;

	c = read_key_press(info);
}

int		main(void)
{
	t_info	*info;
	
	info = NULL;
	enable_rawmode(info);
	process_key_press(info);
}