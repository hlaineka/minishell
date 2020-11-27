/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:00:59 by hlaineka          #+#    #+#             */
/*   Updated: 2020/11/26 17:02:44 by hlaineka         ###   ########.fr       */
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