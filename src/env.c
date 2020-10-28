/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:39:26 by hlaineka          #+#    #+#             */
/*   Updated: 2020/10/28 14:21:51 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_env(t_editor *info)
{
	int			i;
	char		*temp;
	
	i = 0;
	while (info->envp_pointer[i])
	{
		temp = ft_strjoin(info->envp_pointer[i++], "\n");
		ft_putstr(temp);
		free(temp);
	}
}