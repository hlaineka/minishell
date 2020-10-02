/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:34:37 by hlaineka          #+#    #+#             */
/*   Updated: 2020/05/19 09:20:39 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Allocates and returns an array of "fresh" strings (all ending with '\0'
** including the array itself) obtained by splitting s using the character c
** as a delimeter. I the allocation fails, the function returns NULL
*/

static int	number_of_words(const char *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
		{
			if (s[i + 1] == c || s[i + 1] == '\0')
				counter++;
			i++;
		}
		i++;
	}
	return (counter);
}

char		**ft_strsplit(const char *s, char c)
{
	int		i;
	size_t	len;
	char	**returnable;
	int		words;

	i = 0;
	len = 0;
	words = 0;
	returnable = (char**)malloc(sizeof(char*) * number_of_words(s, c));
	if (s && returnable && number_of_words(s, c) > 0)
	{
		while (words < number_of_words(s, c))
		{
			while (s[i] == c && s[i] != '\0')
				i++;
			while (s[i + len] != c && s[i + len] != '\0')
				len++;
			returnable[words] = ft_strdup(ft_strsub(s, i, len));
			words++;
			i = i + len;
			len = 0;
		}
		returnable[words] = NULL;
	}
	return (returnable);
}
