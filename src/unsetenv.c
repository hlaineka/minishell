/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:38:14 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:25:28 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** A build in function, used to unset envp values. Can take multiple parameters.
*/

/*
** Creates a new envp strarray, with the env_index excluded.
*/

static void	create_new_envp(char ***envp, int env_index)
{
	int		i;
	int		w;
	char	**temp;

	i = 0;
	w = 0;
	temp = (char**)malloc(sizeof(char*) * ft_array_length(*envp));
	while (*envp)
	{
		if (i == env_index)
			i++;
		if (!envp[0][i])
			break ;
		temp[w] = ft_strdup(envp[0][i]);
		i++;
		w++;
	}
	temp[w] = NULL;
	ft_strarray_free(*envp);
	*envp = temp;
}

/*
** the main function for unsetenv. goes through the argument list in a while
** and checks if there is an index for the given value name in the envp.
*/

int			ft_unsetenv(char **argv, char ***envp)
{
	int		argv_i;
	int		env_index;

	argv_i = 1;
	while (argv[argv_i])
	{
		env_index = getenv_index(*envp, argv[argv_i]);
		if (env_index == -1)
		{
			argv_i++;
			continue;
		}
		create_new_envp(envp, env_index);
		argv_i++;
	}
	return (1);
}

/*
** Basically the same function as above, but with different arguments
** Made to help env handle parameters given to it.
*/

char		**ft_envhelper_unset(char *str, char **envp)
{
	int		i;
	int		w;
	int		env_index;
	char	**temp;

	env_index = getenv_index(envp, str);
	if (env_index == -1)
		return (envp);
	i = 0;
	w = 0;
	temp = (char**)malloc(sizeof(char*) * ft_array_length(envp));
	while (envp[i])
	{
		if (i == env_index)
			i++;
		if (!envp[i])
			break ;
		temp[w] = ft_strdup(envp[i]);
		i++;
		w++;
	}
	temp[w] = NULL;
	ft_strarray_free(envp);
	return (temp);
}
