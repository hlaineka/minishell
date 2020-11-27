/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_find_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 10:27:33 by hlaineka          #+#    #+#             */
/*   Updated: 2020/11/27 09:45:26 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** returns the index of the first occurance of c in src
*/

int		ft_str_find_c(const char *src, int c)
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
				return (i);
			i++;
		}
		if (src[i] == c)
			return (i);
	}
	return (-1);
}