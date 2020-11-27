/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:38:14 by hlaineka          #+#    #+#             */
/*   Updated: 2020/11/27 12:01:30 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		ft_unsetenv(char **argv, t_editor *info)
{
	int		i;
	int		w;
	int		env_index;
	char	**temp;

	if (ft_array_length(argv) != 2)
		return;
	env_index = getenv_index(info->envp_pointer, argv[1]);
	if (env_index == -1)
		return;
	i = 0;
	w = 0;
	temp = (char**)malloc(sizeof(char*) * ft_array_length(info->envp_pointer));
	while(info->envp_pointer[i])
	{
		if (i == env_index)
			i++;
		if (!info->envp_pointer[i])
			break;
		temp[w] = ft_strdup(info->envp_pointer[i]);
		i++;
		w++;
	}
	temp[w] = NULL;
	ft_strarray_free(info->envp_pointer);
	info->envp_pointer = temp;
}
