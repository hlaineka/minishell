/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:13:32 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:27:01 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** takes as a parameter a string and returns its value as an integer
** removes all whitespace in front of the strings and takes into account
** minus and plus signs
*/

int			ft_atoi(const char *str)
{
	int i;
	int	negative_multiplier;
	int returnable;

	i = 0;
	negative_multiplier = 1;
	returnable = 0;
	while (ft_is_whitespace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negative_multiplier = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		returnable = returnable * 10 + (str[i] - '0');
		i++;
	}
	return (returnable * negative_multiplier);
}
