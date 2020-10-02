/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:22:06 by hlaineka          #+#    #+#             */
/*   Updated: 2020/05/19 09:16:49 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** compares up to num characters of str2 to str1. Returns 0 if strings are
** aqual or an integer representing the difference.
*/

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	int		i;

	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0' && str1[i] != str2[i]
			&& num >= 0)
	{
		i++;
		num--;
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
