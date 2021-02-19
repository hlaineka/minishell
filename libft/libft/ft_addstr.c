/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 11:54:01 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:26:38 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Adds a new string to string array. When using with  empty strarray, set the
** pointer to NULL
*/

char	**ft_addstr(char **dest, char *src)
{
	int		i;
	int		w;
	char	**returnable;

	i = 0;
	if (dest)
	{
		while (dest[i] != NULL)
			i++;
	}
	returnable = (char**)malloc(sizeof(char*) * (i + 1));
	w = 0;
	while (w < i)
	{
		returnable[w] = ft_strdup(dest[w]);
		free(dest[w]);
		w++;
	}
	returnable[w] = ft_strdup(src);
	returnable[w + 1] = NULL;
	free(dest);
	return (returnable);
}
