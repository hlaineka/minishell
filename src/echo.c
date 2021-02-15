/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:51:43 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/14 21:01:06 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
** A build in function to implement the echo command. Handles the parameter
** -n. Only prints to the stdout.
*/

int		ft_echo(char **argv)
{
	int	i;
	int	no_newline;

	i = 1;
	no_newline = 0;
	if (argv[i] && ft_strequ(argv[i], "-n"))
	{
		no_newline = 1;
		i++;
	}
	while (argv[i])
	{
		ft_putstr(argv[i]);
		ft_putchar(' ');
		i++;
	}
	if (!no_newline)
		ft_putchar('\n');
	return (1);
}
