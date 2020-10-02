/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpaste_digits.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 12:47:39 by hlaineka          #+#    #+#             */
/*   Updated: 2020/05/19 09:20:11 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** pastes the digits of the string in src to the beginning of the dest.
** Does not add \0
*/

void		ft_strpaste_digits(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		if (ft_isdigit(src[i]))
			dest[i] = src[i];
		i++;
	}
}
