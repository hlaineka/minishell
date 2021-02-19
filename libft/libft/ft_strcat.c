/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:32:22 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:32:19 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** appends a copy of the src to dest, with terminating null-character.
** dests terminating null is overwritten. dest and src should not overlap
*/

char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int w;

	i = 0;
	w = 0;
	while (dest[i] != '\0')
		i++;
	while (src[w] != '\0')
	{
		dest[i] = src[w];
		i++;
		w++;
	}
	dest[i] = '\0';
	return (dest);
}
