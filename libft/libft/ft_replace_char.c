/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 13:58:24 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/08 12:49:51 by hlaineka         ###   ########.fr       */
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

	new_len = ft_strlen(src) + ft_strlen(input);
	returnable = (char*)malloc(sizeof(char) * (new_len + 1));
	returnable_i = 0;
	src_i = 0;
	input_i = 0;
	while(src[src_i] != '\0')
	{
		if (returnable_i == i)
		{
			while(input && input[input_i])
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
	return(returnable);
}