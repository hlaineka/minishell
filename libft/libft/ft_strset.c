/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 12:48:37 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:34:43 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function creates a new string of size num, and allocates it with
** char value. The fresh string is then returned.
*/

char	*ft_strset(char value, size_t num)
{
	unsigned int	i;
	char			*returnable;

	i = 0;
	if ((returnable = (char*)malloc(sizeof(char) * (num + 1))) != NULL)
	{
		while (i < num)
		{
			returnable[i] = value;
			i++;
		}
		returnable[i] = '\0';
	}
	return (returnable);
}
