/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:29:23 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/15 12:50:13 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
** A function used to exit the program in controlled manner. Retrieves the
** saved termios value and applies it to the shell, returning it from the
** rawmode state. The argv can have a number parameter that is used as a return
** value of the program truncated in to a single byte (char). All other
** parameters are dismissed.
*/

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
	exit((int)returnable_c);
}
