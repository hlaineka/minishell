/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:29:23 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/02 15:30:15 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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