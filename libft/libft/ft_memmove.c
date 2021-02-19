/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 12:32:47 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:30:31 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** copies num characters from dest to src. works also on overlapping memory
** areas
*/

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	unsigned char		*temp_dest;
	unsigned const char	*temp_src;
	unsigned int		i;

	temp_dest = dest;
	temp_src = src;
	i = 0;
	if (dest && src)
	{
		if (temp_dest < temp_src)
		{
			while (i < num)
			{
				temp_dest[i] = temp_src[i];
				i++;
			}
		}
		else
		{
			while (num-- > 0)
				temp_dest[num] = temp_src[num];
		}
	}
	return (dest);
}
