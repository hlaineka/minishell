/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_addfront.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:01:02 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:32:04 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Adds a new string to the beginning of string array. Frees the old strarr
** and all the str in it. The string and array must be null-terminated.
*/

#include "libft.h"

char	**ft_strarr_addfront(char **arr, char *str)
{
	char	**returnable;
	int		i;

	i = 0;
	returnable = (char**)malloc(sizeof(char*) * ft_array_length(arr) + 2);
	returnable[i] = ft_strdup(str);
	while (arr[i])
	{
		returnable[i + 1] = ft_strdup(arr[i]);
		i++;
	}
	returnable[i] = NULL;
	ft_strarray_free(arr);
	return (returnable);
}
