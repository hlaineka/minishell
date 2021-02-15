/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:00:59 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/15 19:32:28 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** frees the passed variable, and sets it to NULL
*/

#include "../includes/libft.h"

void	ft_free(void *variable)
{
	free(variable);
	variable = NULL;
}
