/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 12:57:41 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:24:35 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** A build in function used to print the current working folder. Works also
** the envp variable PWD is unset.
*/

/*
** a function used to retrieve the value of the PWD variable fromt the envp
** list given as a parameter. If PWD is unset, retriews the pwd value with
** getcwd() c funtion. Also used by other functions that ft_pwd().
*/

char	*get_pwd(char **envp)
{
	char	*returnable;
	int		i;

	i = getenv_index(envp, "PWD");
	if (i == -1)
		returnable = getcwd(NULL, 0);
	else
		returnable = ft_getenv(envp, "PWD");
	return (returnable);
}

/*
** The main function for pwd build in. Retrieves the value of the current
** working directory with get_pwd() and prints it to the standart output.
*/

int		ft_pwd(char **envp)
{
	char	*printable;

	printable = get_pwd(envp);
	ft_printf("%s\n", printable);
	free(printable);
	return (1);
}
