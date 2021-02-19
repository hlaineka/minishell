/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynamic_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 11:17:49 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:27:17 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** dynamically allocates more space for string as more data is added to it.
** handles memory so that there are no memoryleaks. The incoming string does
** not have to be nullterminated, mut the length of the string is required.
** Good when used with read().
*/

char		*ft_dynamic_string(char **dest, char *src, int num)
{
	char	*returnable;
	char	*temp_src;

	temp_src = (char*)malloc(sizeof(char) * (num + 1));
	temp_src = ft_memcpy(temp_src, src, num);
	temp_src[num] = '\0';
	returnable = NULL;
	if (!*dest)
		*dest = ft_strdup(temp_src);
	else
	{
		returnable = ft_strjoin(*dest, temp_src);
		free(temp_src);
		temp_src = *dest;
		*dest = ft_strdup(returnable);
		free(returnable);
	}
	free(temp_src);
	return (*dest);
}
