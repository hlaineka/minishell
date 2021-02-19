/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:42:08 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:33:41 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applies the function f to each character of the string given as argument
** to create a "fresh" new string restulting from the successice applications
** of f.
*/

char	*ft_strmap(const char *s, char (*f)(char))
{
	int		i;
	char	*returnable;

	i = 0;
	returnable = ft_strnew(ft_strlen(s));
	if (s && returnable && f)
	{
		while (s[i] != '\0')
		{
			returnable[i] = f(s[i]);
			i++;
		}
		returnable[i] = '\0';
	}
	return (returnable);
}
