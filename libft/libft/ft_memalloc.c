/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:18:01 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:30:02 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** allocates size amount of bytes of memory as zero
*/

void	*ft_memalloc(size_t size)
{
	char	*returnable;

	returnable = (char*)malloc(sizeof(char) * size);
	if (returnable == NULL)
		return (NULL);
	ft_bzero(returnable, size);
	return ((void*)returnable);
}
