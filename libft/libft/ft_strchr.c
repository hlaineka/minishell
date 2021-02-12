/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:33:07 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/12 16:33:46 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** returns a pointer to the first occurance of c in src
*/

char	*ft_strchr(const char *src, int c)
{
	int		i;

	i = 0;
	if (src)
	{
		while (src[i] != '\0')
		{
			if (src[i] == c)
				return (char*)&src[i];
			i++;
		}
		if (src[i] == c)
			return (char*)&src[i];
	}
	return (NULL);
}
