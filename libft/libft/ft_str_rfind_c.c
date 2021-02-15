/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_rfind_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 16:07:06 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/15 19:40:30 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** returns the index of the last occurance of c in src
*/

int		ft_str_rfind_c(const char *src, int c)
{
	int		i;

	i = ft_strlen(src);
	if (src)
	{
		while (i >= 0)
		{
			if (src[i] == c)
				return (i);
			i--;
		}
	}
	return (0);
}
