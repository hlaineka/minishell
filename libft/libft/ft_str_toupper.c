/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_toupper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 11:26:14 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:31:55 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Turns the str given as a parameter to uppercase.
*/

char	*ft_str_toupper(char *str)
{
	int		i;
	char	*returnable;

	i = 0;
	returnable = (char*)malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[i])
	{
		returnable[i] = ft_toupper(str[i]);
		i++;
	}
	returnable[i] = '\0';
	return (returnable);
}
