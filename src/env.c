/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:39:26 by hlaineka          #+#    #+#             */
/*   Updated: 2021/01/25 13:02:56 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		check_options(char **argv, char ***temp_envp)
{
	if (ft_array_length(argv) == 1)
		return(1);
	if (ft_array_length(argv) == 2 && argv[1][0] == '-')
	{
		if (argv[1][1] == 'i')
		{
			ft_strarray_free(*temp_envp);
			*temp_envp = (char**)malloc(sizeof(char*));
			*temp_envp = NULL;
			ft_strarr_add(*temp_envp, "\0");
		}
	}
	return (1);
}

void	ft_env(char **argv, t_editor *info)
{
	int			i;
	char**		temp_envp;

	i = 0;
	temp_envp = ft_strarr_copy(info->envp_pointer);
	if (!(check_options(argv, &temp_envp)))
		return;
	while (temp_envp && temp_envp[i])
	{
		ft_putstr(temp_envp[i]);
		ft_putstr("\n");
		i++;
	}
}