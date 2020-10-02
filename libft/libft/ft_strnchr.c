/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 10:29:34 by hlaineka          #+#    #+#             */
/*   Updated: 2020/09/29 14:11:21 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** returns a pointer to the last occurance of c in src
*/

static int	last_occurance(const char *src, int c)
{
	int		i;
	char	temp_c;

	i = ft_strlen(src) - 1;
	temp_c = c;
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
