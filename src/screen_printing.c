/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_printing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:10:31 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/14 18:15:50 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
** Function to clear the screen before the minishell prompt starts on startup.
*/

void	clear_screen(void)
{
	write(STDOUT_FILENO, "\x1b[2J", 4);
	write(STDOUT_FILENO, "\x1b[H", 3);
}

/*
** A small function to print info on this minishell.
*/

int		print_info(void)
{
	ft_printf("This shell was coded by Helvi Lainekallio (hlaineka) as a ");
	ft_printf("part of Hive Helsinki studies. \n");
	ft_printf("Code and subject of the project can be found on ");
	ft_printf("https://github.com/hlaineka/minishell.\n");
	ft_printf("Only allowed readymade functions in this project are listed ");
	ft_printf("below. Everything else coded by me, including my own printf, ");
	ft_printf("ls-command and c-library.\n");
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
	return (1);
}

/*
** Reprints row from prompt forward.
** [D moves cursor to left and [K clears the line right of cursor
*/

void	reprint_row(char *command, int length, int cursorshift)
{
	while (length > 0)
	{
		ft_printf("\033[D");
		length--;
	}
	ft_printf("\033[K");
	if (command)
		ft_printf("%s", command);
	while (cursorshift < 0)
	{
		ft_printf("\033[D");
		cursorshift++;
	}
}
