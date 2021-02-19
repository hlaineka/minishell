/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 10:55:32 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:25:14 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** setenv build in saves a new value to the env environment variable list,
** or replaces a existing one. A lot of these functions are used by other
** functions in the program to search through the env variable list.
*/

/*
** A static function used to print the environment variable list.
*/

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

/*
** getenv_index returns the index of the variable named _name_ in the envp
** array given as a parameter. This way it can be used also with env function
** with temporary envp variable list. If the instance is not found on the
** envp_pointer list, getenv_index() returns -1
*/

int			getenv_index(char **envp_pointer, char *name)
{
	char	**temp_strarray;
	char	*temp;
	int		i;

	i = 0;
	temp_strarray = envp_pointer;
	while (temp_strarray && temp_strarray[i])
	{
		temp = ft_strsub(temp_strarray[i], 0,
				ft_str_find_c(temp_strarray[i], '='));
		if (ft_strequ(temp, name))
		{
			free(temp);
			return (i);
		}
		ft_free(temp);
		i++;
	}
	return (-1);
}

/*
** add_str_to_env() gets as a parameter an envp list, the new value
** that is of type NAME=value and the index where it should be placed.
** if the index is -1, meaning that the value is not in envp, adds the
** value to the end of the envp list. Otherwise substitutes the value on
** index i with the new value.
*/

char		**add_str_to_env(char **envp, char *new_value, int i)
{
	int		array_size;
	char	**new_envp;
	int		w;

	array_size = 0;
	array_size = ft_array_length(envp);
	w = 0;
	if (i == -1)
		return (ft_strarr_add(envp, new_value));
	new_envp = (char**)malloc(sizeof(char*) * (array_size + 1));
	while (envp && envp[w])
	{
		if (w == i)
			new_envp[w] = ft_strdup(new_value);
		else
			new_envp[w] = ft_strdup(envp[w]);
		w++;
	}
	new_envp[w] = NULL;
	ft_strarray_free(envp);
	return (new_envp);
}

/*
** Prints the usade of setenv in case paramaters for the function were
** not correct.
*/

static int	print_setenv_usage(void)
{
	ft_putstr("setenv: wrong amount or usage of args\n");
	ft_putstr("usage: setenv [VAR] [word] ... \n");
	return (1);
}

/*
** The main function for setenv build in. Checks that the function is given
** necessary amount of parameters and if the parameter has a value '=',
** and if not, prints usage and returns. otherwise adds the new value to the
** envp variable given as a parameter. Always returns 1.
*/

int			ft_setenv(char **argv, char ***envp)
{
	char	*new_value;
	int		array_size;
	int		i;

	i = 1;
	array_size = ft_array_length(argv);
	if (array_size == 1 && ft_strequ(argv[0], "setenv"))
	{
		print_all(*envp);
		return (1);
	}
	while (argv[i])
	{
		if (!argv[i + 1] || ft_strchr(argv[i], '=') ||
				ft_strchr(argv[i + 1], '='))
			return (print_setenv_usage());
		new_value = ft_strjoin3(argv[i], "=", argv[i + 1]);
		*envp = add_str_to_env(*envp, new_value, getenv_index(*envp, argv[i]));
		free(new_value);
		i = i + 2;
	}
	return (1);
}
