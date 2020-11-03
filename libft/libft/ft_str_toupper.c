/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_toupper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 11:26:14 by hlaineka          #+#    #+#             */
/*   Updated: 2020/11/03 14:30:57 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_str_toupper(char *str)
{
	int		i;
	char	*returnable;

	i = 0;
	returnable = (char*)malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[i])
	{
		returnable[i] = ft_toupper(str[i]);
		i++;
	}
	returnable[i] = '\0';
	return(returnable);
}
