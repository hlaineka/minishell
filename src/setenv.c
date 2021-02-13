/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 10:55:32 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/13 11:30:43 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	print_all(char **envp)
{
	int			i;
	char		*temp;
	
	i = 0;
	while (envp[i])
	{
		temp = ft_strjoin(envp[i++], "\n");
		ft_putstr(temp);
		ft_free(temp);
	}
}

int		getenv_index(char **envp_pointer, char *name)
{
	char	**temp_strarray;
	char	*temp;
	int		i;

	i = 0;
	temp_strarray = envp_pointer;
	while(temp_strarray && temp_strarray[i])
	{
		temp = ft_strsub(temp_strarray[i], 0, ft_str_find_c(temp_strarray[i], '='));
		if (ft_strequ(temp, name))
		{
			free(temp);
			return(i);
		}
		ft_free(temp);
		i++;
	}
	return (-1);
}


char		**add_str_to_env(char **envp, char *new_value, int i)
{
	int		array_size;
	char	**new_envp;
	int		w;
	
	array_size = 0;
	array_size = ft_array_length(envp);
	w = 0;
	if (i == -1)
		return(ft_strarr_add(envp, new_value));
	new_envp = (char**)malloc(sizeof(char*) * (array_size + 1));
	while(envp && envp[w])
	{
		if (w == i)
			new_envp[w] = ft_strdup(new_value);
		else
			new_envp[w] = ft_strdup(envp[w]);
		w++;
	}
	new_envp[w] = NULL;
	ft_strarray_free(envp);
	return(new_envp);
}

void	print_setenv_usage()
{
	ft_putstr("setenv: wrong amount of args\n");
	ft_putstr("usage: setenv [VAR] [word]\n");
}

void		ft_setenv(char **argv, char ***envp)
{
	char	*new_value;
	int		array_size;
	
	array_size = ft_array_length(argv);
	if (array_size == 1 && ft_strequ(argv[0], "setenv"))
		print_all(*envp);
	if (array_size != 3 || !ft_strequ(argv[0], "setenv"))
	{
		print_setenv_usage();
		return ;
	}
	new_value = ft_strjoin3(argv[1], "=", argv[2]);
	*envp = add_str_to_env(*envp, new_value, getenv_index(*envp, argv[1]));
	free(new_value);
}