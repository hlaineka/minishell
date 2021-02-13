/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:38:14 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/13 11:48:05 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		ft_unsetenv(char **argv, char ***envp)
{
	int		i;
	int		w;
	int		env_index;
	char	**temp;

	if (ft_array_length(argv) != 2)
		return;
	env_index = getenv_index(*envp, argv[1]);
	if (env_index == -1)
		return;
	i = 0;
	w = 0;
	temp = (char**)malloc(sizeof(char*) * ft_array_length(*envp));
	while(*envp)
	{
		if (i == env_index)
			i++;
		if (!envp[0][i])
			break;
		temp[w] = ft_strdup(envp[0][i]);
		i++;
		w++;
	}
	temp[w] = NULL;
	ft_strarray_free(*envp);
	*envp = temp;
}

char	**ft_envhelper_unset(char* str, char **envp)
{
	int		i;
	int		w;
	int		env_index;
	char	**temp;

	env_index = getenv_index(envp, str);
	if (env_index == -1)
		return envp;
	i = 0;
	w = 0;
	temp = (char**)malloc(sizeof(char*) * ft_array_length(envp));
	while(envp[i])
	{
		if (i == env_index)
			i++;
		if (!envp[i])
			break;
		temp[w] = ft_strdup(envp[i]);
		i++;
		w++;
	}
	temp[w] = NULL;
	ft_strarray_free(envp);
	return(temp);
}
