/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_deli.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 11:22:26 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/15 19:19:09 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Deletes the char in index i.
*/

void	ft_str_deli(char **str, int i)
{
	char	*temp;
	char	*temp2;
	char	*new_str;

	if (i >= (int)ft_strlen(*str))
		return ;
	if (i < 0)
		i = 0;
	temp = ft_strsub(*str, 0, i);
	if ((i + 1) < (int)ft_strlen(*str))
	{
		temp2 = ft_strsub(*str, i + 1, ft_strlen(*str) - i - 1);
		new_str = ft_strjoin(temp, temp2);
	}
	else
		new_str = ft_strdup(temp);
	ft_free(*str);
	*str = new_str;
	ft_free(temp);
	ft_free(temp2);
}
