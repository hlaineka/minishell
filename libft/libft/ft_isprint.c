/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:16:36 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:28:08 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** checks if c is printable ascii character (return 1) or not (returns 0)
*/

int	ft_isprint(int c)
{
	if ((c > 31 && c < 127) || c == '\n' || c == '\t')
		return (1);
	return (0);
}
