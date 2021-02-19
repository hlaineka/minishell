/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpaste_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 12:49:44 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:34:26 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** pastes the string (form end to beginning) in src to the dest.
** (from end to beginning)
*/

void		ft_strpaste_end(char *dest, char *src)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (src[i] != '\0')
		i++;
	while (dest[w] != '\0')
		w++;
	while (i >= 0 && w >= 0)
		dest[w--] = src[i--];
}
