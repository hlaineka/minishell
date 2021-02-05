/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 12:23:25 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/04 15:43:09 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Allocates and returns a "fresh" substring from the string given as argument.
** The substring begins at index START and is of size LEN. If START and LEN
** aren't refering to a valid substring, the behavior is undefined. If the
** allocation fails, the function return NULL
*/

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char			*returnable;
	unsigned int	i;
	
	i = 0;
	if (s && (returnable = (char*)malloc(sizeof(char) * (len + 1))))
	{
		while (i < len)
		{
			returnable[i] = s[start + i];
			i++;
		}
		returnable[i] = '\0';
		return (returnable);
	}
	return (NULL);
}
