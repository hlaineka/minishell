/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:39:26 by hlaineka          #+#    #+#             */
/*   Updated: 2020/10/30 14:56:03 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_env(t_editor *info)
{
	int			i;
	char		*temp;
	char		**temp_envp;
	
	i = 0;
	temp_envp = info->envp_pointer;
	while (temp_envp[i])
	{
		temp = ft_strjoin(temp_envp[i++], "\n");
		ft_putstr(temp);
		free(temp);
	}
}