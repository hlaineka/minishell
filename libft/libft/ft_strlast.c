/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 10:42:46 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:33:27 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Finds the last character of string and returns it.
*/

char	ft_strlast(char const *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
		return (str[i - 1]);
	}
	return (0);
}
