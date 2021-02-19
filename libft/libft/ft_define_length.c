/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_define_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 10:28:47 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:27:13 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** counts how many characters  an integer has
*/

int	ft_define_length(int n)
{
	int i;

	i = 1;
	if (n == T_INT_MIN)
	{
		i = i + 2;
		n = 147483648;
	}
	if (n < 0)
	{
		i++;
		n = n * (-1);
	}
	while ((n / 10) > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}
