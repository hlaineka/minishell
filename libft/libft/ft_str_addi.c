/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_addi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 11:30:33 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/05 13:02:04 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Add the char c to index i.
*/

char	*ft_str_addi(const char *str, int i, char c)
{
	char	*temp;
	char	*temp2;
	char	*temp3;
	char	*returnable;

	temp = ft_strsub(str, 0, i);
	temp2 = ft_strsub(str, i, ft_strlen(str) - i);
	temp3 = (char*)malloc(sizeof(char) * 2);
	temp3[0] = c;
	temp3[1] = '\0';
	returnable = ft_strjoin3(temp, temp3, temp2);
	ft_free(temp);
	ft_free(temp2);
	ft_free(temp3);
	return(returnable);
}