/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 13:58:24 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:31:21 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** replaces the char in given index with the given input string in src string.
** frees the string in src.
*/

#include "libft.h"

char	*ft_replc(char *src, int i, char *input)
{
	char	*returnable;
	int		returnable_i;
	int		src_i;
	int		input_i;

	returnable = (char*)malloc(ft_strlen(src) + ft_strlen(input) + 1);
	returnable_i = 0;
	src_i = 0;
	input_i = 0;
	while (src && src[src_i] != '\0')
	{
		if (returnable_i == i)
		{
			while (input && input[input_i])
				returnable[returnable_i++] = input[input_i++];
		}
		else
			returnable[returnable_i++] = src[src_i];
		src_i++;
	}
	returnable[returnable_i] = '\0';
	return (returnable);
}
