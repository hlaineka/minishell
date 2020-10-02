/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:04:53 by hlaineka          #+#    #+#             */
/*   Updated: 2020/05/19 09:20:01 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** allocates new string of SIZE and initializes it with \0
*/

char	*ft_strnew(size_t size)
{
	unsigned int	i;
	char			*returnable;

	i = 0;
	if ((returnable = (char*)malloc(sizeof(char) * size + 1)))
	{
		while (i < size)
		{
			returnable[i] = '\0';
			i++;
		}
		returnable[i] = '\0';
		return (returnable);
	}
	return (NULL);
}
