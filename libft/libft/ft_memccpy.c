/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:25:55 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:30:06 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** copies no more than n bytes from memory src to dest, stopping when
** char c is found
*/

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char			*temp_dest;
	const unsigned char		*temp_src;
	unsigned int			i;
	unsigned char			temp_c;

	temp_c = c;
	temp_dest = dest;
	temp_src = src;
	i = 0;
	while (i < n)
	{
		temp_dest[i] = temp_src[i];
		if (temp_src[i] == temp_c)
			return (&temp_dest[i + 1]);
		i++;
	}
	return (NULL);
}
