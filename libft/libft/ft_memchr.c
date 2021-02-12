/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:19:55 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/12 16:33:14 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** searches num bytes on ptr to find c (interpreted as unsigned int)
** When c is found, returns a pointer to it.
*/

void	*ft_memchr(const void *ptr, int c, size_t num)
{
	unsigned int		i;
	unsigned char		*temp_ptr;
	unsigned char		temp_c;

	temp_ptr = (unsigned char*)ptr;
	temp_c = c;
	i = 0;
	while (i < num)
	{
		if (*temp_ptr == temp_c)
			return (temp_ptr);
		temp_ptr++;
		i++;
	}
	return (NULL);
}
