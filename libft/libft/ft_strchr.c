/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:33:07 by hlaineka          #+#    #+#             */
/*   Updated: 2020/05/19 09:15:17 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** returns a pointer to the first occurance of c in src
*/

char	*ft_strchr(const char *src, int c)
{
	int		i;
	char	temp_c;

	i = 0;
	temp_c = c;
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
