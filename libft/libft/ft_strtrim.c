/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:36:01 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:35:19 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates and returns a copy of the string given as argument without
** whitespsaces at the beginning or at the end of string. Will be considered as
** whitespaces the following characters ' ', '\n', '\t'. If S has no white-
** spaces at the beginning or at the ends, the function returns a copy of S.
** if allocation fails the function returns NULL
*/

static int	is_whitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(const char *s)
{
	int		i;
	int		w;
	int		u;
	char	*returnable;

	i = 0;
	w = ft_strlen(s) - 1;
	u = 0;
	returnable = ft_strnew(ft_strlen(s) + 1);
	if (returnable)
	{
		while (s[i] && is_whitespace(s[i]))
			i++;
		while (w > i && is_whitespace(s[w]))
			w--;
		while (i <= w)
		{
			returnable[u] = s[i];
			i++;
			u++;
		}
		returnable[i] = '\0';
		return (returnable);
	}
	return (NULL);
}
