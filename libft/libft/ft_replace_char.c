/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 13:58:24 by hlaineka          #+#    #+#             */
/*   Updated: 2020/11/27 14:17:12 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** replaces the char in given index with the given input string in src string.
** frees the string in src.
*/

#include "../includes/libft.h"

char	*ft_replace_char(char *src, int i, char *input)
{
	char	*returnable;
	int		returnable_i;
	int		src_i;
	int		input_i;
	int		new_len;

	new_len = ft_strlen(src) + ft_strlen(input) - 1;
	returnable = (char*)malloc(new_len);
	returnable_i = 0;
	src_i = 0;
	input_i = 0;
	while(returnable_i < new_len)
	{
		if (returnable_i == i)
		{
			while(input[input_i])
			{
				returnable[returnable_i] = input[input_i];
				returnable_i++;
				input_i++;
			}
		}
		else
			returnable[returnable_i++] = src[src_i];
		src_i++;
	}
	returnable[returnable_i] = '\0';
	ft_free(src);
	return(returnable);
}