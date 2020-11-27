/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 10:55:32 by hlaineka          #+#    #+#             */
/*   Updated: 2020/11/27 11:44:54 by hlaineka         ###   ########.fr       */
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
	while(temp_strarray[i])
	{
		temp = ft_strsub(temp_strarray[i], 0, ft_str_find_c(temp_strarray[i], '='));
		if (ft_strequ(temp, name))
			return(i);
		ft_free(temp);
		i++;
	}
	return (-1);
}

char		**copy_env(char **envp, char *dest, char *value)
{
	int		array_size;
	char	**new_envp;
	int		i;
	int		w;
	
	i = getenv_index(envp, dest);
	array_size = ft_array_length(envp);
	w = 0;
	new_envp = (char**)malloc(sizeof(char*) * array_size + 2);
	while(envp[w])
	{
		if (w == i)
			new_envp[w] = ft_strjoin3(dest, "=", value);
		else
			new_envp[w] = ft_strdup(envp[w]);
		w++;
	}
	if (i == -1)
		new_envp[w++] = ft_strjoin3(dest, "=", value);
	new_envp[w] = NULL;
	return(new_envp);
}

void		ft_setenv(char **argv, t_editor *info)
{
	char	*dest;
	char	*value;
	int		array_size;
	char	**temp;
	
	array_size = ft_array_length(argv);
	if (array_size == 1 && ft_strequ(argv[0], "setenv"))
		print_all(info->envp_pointer);
	if (array_size != 3 || !ft_strequ(argv[0], "setenv"))
		return ;
	dest = ft_strdup(argv[1]);
	value = ft_strdup(argv[2]);
	temp = copy_env(info->envp_pointer, dest, value);
	ft_strarray_free(info->envp_pointer);
	info->envp_pointer = temp;
	ft_free(value);
	ft_free(dest);
}