/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 10:43:21 by hlaineka          #+#    #+#             */
/*   Updated: 2020/06/18 10:43:26 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lst_split(t_list *first, t_list **a, t_list **b)
{
	int		i;
	int		w;
	t_list	*temp;

	*a = first;
	*b = NULL;
	if (!first || !first->next)
		return ;
	w = ft_lst_length(first) / 2;
	temp = *a;
	i = 1;
	while (i < w && temp && temp->next)
	{
		temp = temp->next;
		i++;
	}
	*b = temp->next;
	temp->next = NULL;
}
