/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:34:18 by hlaineka          #+#    #+#             */
/*   Updated: 2020/05/19 09:15:42 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** creates a new string and copies the content of s to it.Returns the new str
*/

char	*ft_strdup(const char *s)
{
	int		i;
	char	*returnable;
	int		length;

	length = ft_strlen(s);
	returnable = (char*)malloc(sizeof(char) * (length + 1));
	i = 0;
	if (s == NULL || !returnable)
		return (NULL);
	if (returnable)
	{
		while (s[i] != '\0')
		{
			returnable[i] = s[i];
			i++;
		}
		returnable[i] = '\0';
	}
	return (returnable);
}
