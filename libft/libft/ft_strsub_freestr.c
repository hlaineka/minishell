/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_freestr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 12:50:26 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/01 16:01:25 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Allocates and returns a "fresh" substring from the string given as argument.
** The substring begins at index START and is of size LEN. If START and LEN
** aren't refering to a valid substring, the behavior is undefined. If the
** allocation fails, the function return NULL. Frees the str given as parameter.
*/

char	*ft_strsub_freestr(char *s, unsigned int start, size_t len)
{
	char			*returnable;
	unsigned int	i;

	i = 0;
	if (s && (returnable = (char*)malloc(sizeof(char) * len + 1)))
	{
		while (i < len)
		{
			returnable[i] = s[start + i];
			i++;
		}
		returnable[i] = '\0';
		return (returnable);
	}
	ft_free(s);
	return (NULL);
}
