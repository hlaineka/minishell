/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_freestr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 12:50:26 by hlaineka          #+#    #+#             */
/*   Updated: 2020/05/19 09:20:48 by helvi            ###   ########.fr       */
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

	returnable = (char*)malloc(sizeof(char) * len + 1);
	i = 0;
	if (returnable)
	{
		while (i < len)
		{
			returnable[i] = s[start + i];
			i++;
		}
		returnable[i] = '\0';
		return (returnable);
	}
	free(s);
	return (NULL);
}
