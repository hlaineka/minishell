/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_sorted_merge.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 10:42:55 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:28:56 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_sorted_merge(t_list *a, t_list *b, int (*f)(t_list *elem_a,
		t_list *elem_b))
{
	t_list	*temp;

	temp = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (f(a, b))
	{
		temp = a;
		temp->next = ft_lst_sorted_merge(a->next, b, f);
	}
	else
	{
		temp = b;
		temp->next = ft_lst_sorted_merge(a, b->next, f);
	}
	return (temp);
}
