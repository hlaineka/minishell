/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_char_join.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 20:15:53 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:31:31 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Creates a new string where it combines the char and string given as
** parameters. Frees the string in s2.
*/

char	*ft_str_char_join(char c, char *s1)
{
	unsigned int	i;
	unsigned int	w;
	char			*returnable;

	if (NULL != (returnable = (char*)malloc(sizeof(char)
				* (ft_strlen(s1) + 2))))
	{
		i = 0;
		w = 0;
		while (s1 && s1[w] != '\0')
		{
			returnable[i] = s1[w];
			i++;
			w++;
		}
		returnable[i] = c;
		returnable[i + 1] = '\0';
		return (returnable);
	}
	return (NULL);
}
