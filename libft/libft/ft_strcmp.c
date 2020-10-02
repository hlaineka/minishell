/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:12:38 by hlaineka          #+#    #+#             */
/*   Updated: 2020/09/26 12:11:40 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** compares str1 to str2 and return 0 if they are aqual or int representing
** the difference.
*/

int	ft_strcmp(const char *str1, const char *str2)
{
	int		i;

	i = 0;
	if (!str1 && !str2)
		return (0);
	if (!str1)
		return (0 - str2[0]);
	if (!str2)
		return (str1[0]);
	while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i])
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
