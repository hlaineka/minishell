/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdellast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 20:28:08 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:29:25 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
