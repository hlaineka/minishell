/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 12:57:41 by hlaineka          #+#    #+#             */
/*   Updated: 2021/01/27 15:18:21 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_pwd(char **envp)
{
	char*	printable;
	int		i;

	i = getenv_index(envp, "PWD");
	if (i == -1)
		printable = getcwd(NULL, 0);
	else
		printable = ft_getenv(envp, "PWD");
	ft_printf("%s\n", printable);
	free(printable);
}