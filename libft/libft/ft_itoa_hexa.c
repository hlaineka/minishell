/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 12:35:48 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:28:28 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_define_hexa_length(uintmax_t n)
{
	int			i;
	uintmax_t	base;

	i = 1;
	base = 16;
	while ((n / base) > 0)
	{
		i++;
		n = n / base;
	}
	return (i);
}

char			*ft_itoa_hexa(uintmax_t n)
{
	static char		*str;
	int				w;
	uintmax_t		base;

	base = 16;
	if (NULL != (str = (char*)malloc(sizeof(char)
					* (ft_define_hexa_length(n) + 1))))
	{
		w = ft_define_hexa_length(n) - 1;
		str[w + 1] = ('\0');
		while (n >= base)
		{
			if (n % base <= 9)
				str[w--] = ((n % base) + '0');
			else
				str[w--] = ((n % base) - 10 + 'a');
			n = n / base;
		}
		if (n <= 9)
			str[w--] = n + '0';
		else
			str[w--] = n - 10 + 'a';
		return (str);
	}
	return (NULL);
}
