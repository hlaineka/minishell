/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 10:42:46 by hlaineka          #+#    #+#             */
/*   Updated: 2020/06/18 10:42:48 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
