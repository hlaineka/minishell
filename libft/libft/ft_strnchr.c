/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 10:29:34 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/12 16:39:25 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** returns a pointer to the last occurance of c in src
*/

static int	last_occurance(const char *src, int c)
{
	int		i;

	i = ft_strlen(src) - 1;
	if (src)
	{
		while (i >= 0)
		{
			if (src[i] == c)
				return (i);
			i--;
		}
		if (src[i] == c)
			return (i);
	}
	return (-1);
}

char		*ft_strnchr(const char *src, int c)
{
	char	*returnable;

	returnable = ft_strsub(src, 0, last_occurance(src, c));
	return (returnable);
}
