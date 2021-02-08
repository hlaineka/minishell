/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:16:36 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/08 11:15:56 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** checks if c is printable ascii character (return 1) or not (returns 0)
*/

int	ft_isprint(int c)
{
	if ((c > 31 && c < 127) || c == '\n' || c == '\t')
		return (1);
	return (0);
}
