/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_rfind_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 16:07:06 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/01 16:12:10 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** returns the index of the last occurance of c in src
*/

int		ft_str_rfind_c(const char *src, int c)
{
	int		i;
	char	temp_c;

	i = ft_strlen(src);
	temp_c = c;
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