/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_frees2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 12:43:29 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:33:14 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Creates a new string where it combines the two strings given as parameters
** Frees the string in s2.
*/

char	*ft_strjoin_frees2(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	w;
	char			*returnable;

	if (s1 && s2)
	{
		if (NULL != (returnable = (char*)malloc(sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2)) + 1)))
		{
			i = 0;
			w = 0;
			while (s1[i] != '\0')
			{
				returnable[i] = s1[i];
				i++;
			}
			while (s2[w] != '\0')
				returnable[i++] = s2[w++];
			returnable[i] = '\0';
			free(s2);
			return (returnable);
		}
	}
	return (NULL);
}
