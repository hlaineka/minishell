/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_printing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:10:31 by hlaineka          #+#    #+#             */
/*   Updated: 2020/11/03 14:23:02 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	clear_screen()
{
	write(STDOUT_FILENO, "\x1b[2J", 4);
	write(STDOUT_FILENO, "\x1b[H", 3);
}

void	print_info()
{
	ft_printf("This shell was coded by Helvi Lainekallio (hlaineka) as a part of Hive\nHelsinki studies. \n");
	ft_printf("Code and subject of the project can be found on\nhttps://github.com/hlaineka/minishell.\n");
	ft_printf("Only allowed readymade functions in this project are listed below. Everything\nelse coded by me, including my own printf, ls-command and c-library.\n");
	ft_printf("\nAllowed readymade functions in this project:\n");
	ft_printf("    * malloc, free\n");
	ft_printf("    * access\n");
	ft_printf("    * open, close, read, write\n");
	ft_printf("    * opendir, readdir, closedir\n");
	ft_printf("    * getcwd, chdir\n");
	ft_printf("    * stat, lstat, fstat\n");
	ft_printf("    * fork, execve\n");
	ft_printf("    * wait, waitpid, wait3, wait4\n");
	ft_printf("    * signal, kill\n");
	ft_printf("    * exit\n");
	ft_printf("\nThe project is not ready, work still in progress!\n\n");

}

void	reprint_row(t_editor *info, char *command)
{
	if (info)
	{
		ft_printf("\r");
		ft_printf("\033[K");
		if (command)
			ft_printf("\r$>%s", command);
	}
}