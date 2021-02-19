/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewtoend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 20:29:01 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:29:54 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Adds given content to the end of the list.
*/

void	ft_lstnewtoend(const void *content, size_t content_size,
		t_list **beginning)
{
	t_list	*newelem;
	t_list	*temp;

	newelem = ft_lstnew(content, content_size);
	temp = ft_lstend(*beginning);
	if (temp == NULL)
		*beginning = newelem;
	else
		ft_lstaddafter(temp, newelem);
	return ;
}
