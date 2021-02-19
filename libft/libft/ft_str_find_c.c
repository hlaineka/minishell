/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_find_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 10:27:33 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:31:40 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** returns the index of the first occurance of c in src
*/

int		ft_str_find_c(const char *src, int c)
{
	int		i;

	i = 0;
	if (src)
	{
		while (src[i] != '\0')
		{
			if (src[i] == c)
				return (i);
			i++;
		}
		if (src[i] == c)
			return (i);
	}
	return (-1);
}
