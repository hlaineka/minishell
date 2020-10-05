/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscntrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 11:24:15 by hlaineka          #+#    #+#             */
/*   Updated: 2020/10/05 11:25:44 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** checks if c is control character (returns 1) or not (returns 0)
*/

int	ft_iscntrl(int c)
{
	if ((c >= 0 && c <= 31) || c == 127)
		return (1);
	return (0);
}