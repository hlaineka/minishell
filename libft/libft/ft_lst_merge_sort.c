/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_merge_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 10:42:51 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:28:47 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_merge_sort(t_list **first, int (*f)(t_list *elem_a,
		t_list *elem_b))
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (!first || !first[0] || !first[0]->next)
		return ;
	ft_lst_split(*first, &a, &b);
	ft_lst_merge_sort(&a, f);
	ft_lst_merge_sort(&b, f);
	*first = ft_lst_sorted_merge(a, b, f);
}
