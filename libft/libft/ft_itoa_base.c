/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 11:22:52 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:28:13 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** turns intiger value to char, using the base given.
*/

int		ft_define_base_length(long long int n, int base)
{
	int				i;
	long long int	int_min;

	int_min = -9223372036854775807;
	i = 1;
	if (n < int_min)
		return (20);
	if (n < 0)
	{
		i++;
		n = n * (-1);
	}
	while ((n / base) > 0)
	{
		i++;
		n = n / base;
	}
	return (i);
}

char	*ft_itoa_base(long long int n, long long int base)
{
	static char	*str;
	int			w;

	w = ft_define_base_length(n, base) - 1;
	if (n < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	if (NULL != (str = (char*)malloc(sizeof(char) *
					(ft_define_base_length(n, base) + 1))))
	{
		str[w + 1] = ('\0');
		if (n < 0)
		{
			str[0] = ('-');
			n = n * (-1);
		}
		while (n >= base)
		{
			str[w--] = ((n % base) + '0');
			n = n / base;
		}
		str[w] = n + '0';
		return (str);
	}
	return (NULL);
}
