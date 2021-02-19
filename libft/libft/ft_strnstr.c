/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:26:07 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:34:18 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** searches through n characters of str1, or until reaches \0
** for an occurance of str2
*/

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	unsigned int	i;
	unsigned int	w;

	i = 0;
	w = 0;
	if (str2[0] == '\0')
		return ((char*)str1);
	while (str1[i] != '\0' && i < n)
	{
		while (str2[w] != '\0' && str1[i + w] != '\0'
			&& (i + w) < n && str2[w] == str1[i + w])
		{
			if (str2[w + 1] == '\0')
				return ((char*)&str1[i]);
			w++;
		}
		i++;
		w = 0;
	}
	return (NULL);
}
