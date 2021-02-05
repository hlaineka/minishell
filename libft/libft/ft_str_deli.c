/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_deli.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 11:22:26 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/05 13:02:11 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Deletes the char in index i.
*/

char	*ft_str_deli(const char *str, int i)
{
	char	*temp;
	char	*temp2;
	char	*returnable;

	if (i >= (int)ft_strlen(str))
		return NULL;
	if (i < 0)
		i = 0;
	temp = ft_strsub(str, 0, i);
	if ((i + 1) < (int)ft_strlen(str))
		temp2 = ft_strsub(str, i + 1, ft_strlen(str) - i - 1);
	else
		temp2 = NULL;
	returnable = ft_strjoin(temp, temp2);
	ft_free(temp);
	ft_free(temp2);
	return(returnable);
}