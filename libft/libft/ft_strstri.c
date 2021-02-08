/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 12:08:35 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/06 12:10:45 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** returns the index of the first occurance of str2 in str1
*/

int		ft_strstri(const char *str1, const char *str2)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	if (str2[0] == '\0')
		return (0);
	while (str1[i] != '\0')
	{
		while (str2[w] != '\0' && str1[i + w] != '\0' && str2[w] == str1[i + w])
		{
			if (str2[w + 1] == '\0')
				return (i);
			w++;
		}
		i++;
		w = 0;
	}
	return (-1);
}