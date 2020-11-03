/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 10:55:32 by hlaineka          #+#    #+#             */
/*   Updated: 2020/11/03 14:34:55 by hlaineka         ###   ########.fr       */
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
		free(temp);
	}
}

static int	getenv_index(char **envp_pointer, char *name)
{
	char	**temp_strarray;
	char	*temp;
	char	*cap_name;
	int		i;

	i = 0;
	temp_strarray = envp_pointer;
	cap_name = ft_str_toupper(name);
	while(temp_strarray[i])
	{
		temp = ft_strsub(temp_strarray[i], 0, ft_str_find_c(temp_strarray[i], '='));
		if (ft_strequ(temp, cap_name))
			return(i);
		free(temp);
		i++;
	}
	free(cap_name);
	return (0);
}

static int	array_length(char **array)
{
	int	i;

	i = 0;
	while(array[i])
		i++;
	return(i);
}

void		ft_setenv(char **argv, char **envp)
{
	int			i;
	char		*dest;
	char		*value;
	char		*temp;
	int			array_size;
	
	i = 0;
	array_size = array_length(argv);
	if (array_size == 1 && ft_strequ(argv[0], "setenv"))
		print_all(envp);
	if (array_size != 3 || !ft_strequ(argv[0], "setenv"))
		return ;
	dest = ft_strdup(argv[1]);
	temp = ft_str_toupper(dest);
	free(dest);
	dest = ft_strdup(temp);
	free(temp);
	value = ft_strdup(argv[2]);
	i = getenv_index(envp, dest);
	array_size = array_length(envp);
	if(i == 0)
	{
		//temp = ft_strmap(dest, &ft_toupper);
		temp = ft_strdup(dest);
		envp[array_size] = ft_strjoin3(temp, "=", value);
		envp[array_size + 1] = NULL;
		free(value);
		free(dest);
		return ;
	}
	else
		envp[i] = ft_strjoin3(dest, "=", value);
	free(value);
	free(dest);
}