/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:18:06 by hlaineka          #+#    #+#             */
/*   Updated: 2020/05/19 09:16:26 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** copies src to dest. Dest can be max size bytes. returns the amount of
** bytes it tried to write
*/

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	int				i;
	int				w;
	unsigned int	dest_len;
	unsigned int	src_len;
	int				temp_size;

	i = 0;
	w = 0;
	temp_size = (int)size;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	while (dest[i] != '\0' && i < temp_size)
		i++;
	if (i == temp_size)
		dest_len = size;
	while (src[w] != '\0' && i < (temp_size - 1))
		dest[i++] = src[w++];
	if (i < temp_size)
	{
		dest[i] = '\0';
		i++;
	}
	return ((unsigned int)(dest_len + src_len));
}
