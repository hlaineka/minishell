/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 20:18:14 by hlaineka          #+#    #+#             */
/*   Updated: 2020/09/16 20:18:51 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_lst_length(t_list *first)
{
	int	i;

	i = 0;
	while (first)
	{
		i++;
		first = first->next;
	}
	return (i);
}
