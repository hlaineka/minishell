/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 10:31:36 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:30:15 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** compares the first num bytes of the two ptr:s and returns zero if they
** are equal or a number representing which is greater. Recursive function
*/

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	const unsigned char	*temp_ptr1;
	const unsigned char *temp_ptr2;

	temp_ptr1 = ptr1;
	temp_ptr2 = ptr2;
	if (num == 0)
		return (0);
	if (temp_ptr1[0] != temp_ptr2[0] || num == 1)
		return (temp_ptr1[0] - temp_ptr2[0]);
	else
		return (ft_memcmp(&temp_ptr1[1], &temp_ptr2[1], num - 1));
}
