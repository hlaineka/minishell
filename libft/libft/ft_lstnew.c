/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:11:40 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:29:50 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** creates a new t_list variable with given content and size. If content is
** NULL, is pointer to content set to NULL and size to zero. Pointer to next
** is always set to NULL
*/

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*returnable;

	returnable = NULL;
	if ((returnable = (t_list*)malloc(sizeof(t_list))))
	{
		if (!content)
			returnable->content_size = 0;
		else
		{
			returnable->content = (void*)malloc(content_size + 1);
			returnable->content = ft_memset(returnable->content, 0,
				content_size + 1);
			returnable->content = ft_memcpy(returnable->content, content,
				content_size);
			returnable->content_size = content_size;
		}
		returnable->next = NULL;
		return (returnable);
	}
	return (NULL);
}
