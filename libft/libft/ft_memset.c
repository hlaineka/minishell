/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:13:24 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:30:34 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** sets num amount of bytes of ptr to value.
*/

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*temp;
	size_t			i;

	temp = ptr;
	i = 0;
	while (i < num)
	{
		temp[i] = value;
		i++;
	}
	return (ptr);
}
