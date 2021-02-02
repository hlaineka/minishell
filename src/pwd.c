/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 12:57:41 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/01 15:46:25 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_pwd(char **envp)
{
	char	*returnable;
	int		i;

	i = getenv_index(envp, "PWD");
	if (i == -1)
		returnable = getcwd(NULL, 0);
	else
		returnable = ft_getenv(envp, "PWD");
}

void	ft_pwd(char **envp)
{
	char*	printable;
	
	printable = get_pwd(envp);
	ft_printf("%s\n", printable);
	free(printable);
}