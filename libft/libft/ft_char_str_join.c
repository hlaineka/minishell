/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_str_join.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 11:09:24 by hlaineka          #+#    #+#             */
/*   Updated: 2020/05/19 09:11:52 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Creates a new string where it combines the char and string given as
** parameters. Frees the string in s2.
*/

char	*ft_char_str_join(char c, char *s1)
{
	unsigned int	i;
	unsigned int	w;
	char			*returnable;

	if (s1)
	{
		if (NULL != (returnable = (char*)malloc(sizeof(char)
					* (ft_strlen(s1) + 1))))
		{
			i = 1;
			w = 0;
			returnable[0] = c;
			while (s1[w] != '\0')
			{
				returnable[i] = s1[w];
				i++;
				w++;
			}
			returnable[i] = '\0';
			free(s1);
			return (returnable);
		}
	}
	return (NULL);
}
