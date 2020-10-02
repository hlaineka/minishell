/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 20:11:01 by hlaineka          #+#    #+#             */
/*   Updated: 2020/09/16 20:11:03 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Finds the last element of the list.
*/

t_list	*ft_lstend(t_list *beginning)
{
	t_list	*temp;

	temp = beginning;
	while (temp != NULL && temp->next != NULL)
		temp = temp->next;
	return (temp);
}
