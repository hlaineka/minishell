/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:19:55 by hlaineka          #+#    #+#             */
/*   Updated: 2020/05/19 09:13:38 by helvi            ###   ########.fr       */
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
	const unsigned char	*temp_ptr;
	unsigned char		temp_c;

	temp_ptr = ptr;
	temp_c = c;
	i = 0;
	while (i < num)
	{
		if (temp_ptr[i] == temp_c)
			return (void*)&ptr[i];
		i++;
	}
	return (NULL);
}
