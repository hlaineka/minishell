/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:39:26 by hlaineka          #+#    #+#             */
/*   Updated: 2020/10/29 19:03:12 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		main(int argc, char **argv, char **envp)
{
	int			i;
	char		*temp;
	
	i = 0;
	if (argc == 1 && ft_strequ(argv[0], "env"))
	{
		while (envp[i])
		{
			temp = ft_strjoin(envp[i++], "\n");
			ft_putstr(temp);
			free(temp);
		}
	}
}