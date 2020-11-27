/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarray_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 11:29:50 by hlaineka          #+#    #+#             */
/*   Updated: 2020/11/27 11:32:15 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** frees all the strings in a NULL terminated array, and then the array itself.
** sets every pointer to NULL after free.
*/

#include "../includes/libft.h"

void ft_strarray_free(char **strarr)
{
	int	i;

	i = 0;
	while(strarr[i])
	{
		ft_free(strarr[i]);
		i++;
	}
	ft_free(strarr);
	return ;
}