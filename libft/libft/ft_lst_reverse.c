/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 16:18:09 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:28:52 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_reverse(t_list **first)
{
	t_list	*temp_previous;
	t_list	*temp_this;
	t_list	*temp_next;

	if (!*first)
		return (NULL);
	temp_previous = *first;
	temp_this = temp_previous->next;
	temp_previous->next = NULL;
	while (temp_this)
	{
		temp_next = temp_this->next;
		temp_this->next = temp_previous;
		temp_previous = temp_this;
		temp_this = temp_next;
	}
	*first = temp_previous;
	return (temp_previous);
}
