/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:51:43 by hlaineka          #+#    #+#             */
/*   Updated: 2021/01/26 18:06:25 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_echo(char **argv)
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
}