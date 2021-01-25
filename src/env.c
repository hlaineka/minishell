/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:39:26 by hlaineka          #+#    #+#             */
/*   Updated: 2021/01/22 16:35:22 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		check_options(char **argv, t_editor *info)
{
	if (ft_array_length(argv) == 1)
		return(1);
	if (ft_array_length(argv) == 2 && argv[1][0] == '-')
	{
		if (argv[1][1] == 'i')
		{
			ft_strarray_free(info->envp_pointer);
			ft_strarr_add(info->envp_pointer, ft_strdup("\0"));
		}
	}
	return (1);
}

void	ft_env(char **argv, t_editor *info)
{
	int			i;
	char		*temp;
	char		**returnable_envp;
	
	i = 0;
	if (!(check_options(argv, info)))
		return;
	returnable_envp = ft_strarr_copy(info->envp_pointer);
	while (returnable_envp[i])
	{
		temp = ft_strjoin(returnable_envp[i++], "\n");
		ft_putstr(temp);
		ft_free(temp);
	}
}