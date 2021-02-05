/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:15:51 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/05 13:12:08 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Creates a new string where it combines the two strings given as parameters
*/

char	*ft_strjoin(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned int	w;
	char			*returnable;

	if (!s1 && s2)
		return (NULL);
	if (NULL != (returnable = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
	{
		i = 0;
		w = 0;
		while (s1 && s1[i] != '\0')
		{
			returnable[i] = s1[i];
			i++;
		}
		while (s2 && s2[w] != '\0')
			returnable[i++] = s2[w++];
		returnable[i] = '\0';
		return (returnable);
	}
	return (NULL);
}
