/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarray_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 11:29:50 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/15 19:26:24 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** frees all the strings in a NULL terminated array, and then the array itself.
** sets every pointer to NULL after free.
*/

#include "../includes/libft.h"

void	ft_strarray_free(char **strarr)
{
	int	i;

	i = 0;
	while (strarr && strarr[i])
	{
		ft_free(strarr[i]);
		i++;
	}
	ft_free(strarr);
	return ;
}
