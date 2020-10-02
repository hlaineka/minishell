/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdellast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 20:28:08 by hlaineka          #+#    #+#             */
/*   Updated: 2020/09/16 20:28:10 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdellast(t_list **first)
{
	t_list	*temp;
	t_list	*last;

	temp = NULL;
	last = first;
	while (last != NULL && last->next != NULL)
	{
		temp = last;
		last = last->next;
	}
}
