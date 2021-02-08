/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:34:18 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/05 17:46:13 by hlaineka         ###   ########.fr       */
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
	returnable = NULL;
	if (!(returnable = (char*)malloc(sizeof(char) * (length + 1))))
		return(NULL);
	i = 0;
	while (s && s[i] != '\0')
	{
		returnable[i] = s[i];
		i++;
	}
	returnable[i] = '\0';
	return (returnable);
}
