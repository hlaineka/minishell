/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddafter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 20:29:55 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:29:11 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Adds given content to the end of the list.
*/

void	ft_lstaddafter(t_list *end, t_list *newelem)
{
	end->next = newelem;
	return ;
}
