/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 12:00:05 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:33:23 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Joins three strings into one in the given order.
*/

char	*ft_strjoin3(char *str1, char *str2, char *str3)
{
	char	*returnable;

	returnable = ft_strjoin(str1, str2);
	returnable = ft_strjoin_frees1(returnable, str3);
	return (returnable);
}
