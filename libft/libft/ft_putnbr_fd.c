/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:08:44 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:31:01 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** prints int n to fd
*/

void	ft_putnbr_fd(int n, int fd)
{
	if (fd >= 0)
	{
		if (n == T_INT_MIN)
		{
			ft_putchar_fd('-', fd);
			ft_putchar_fd('2', fd);
			n = 147483648;
		}
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = n * (-1);
		}
		if (n >= 10)
		{
			ft_putnbr_fd((n / 10), fd);
		}
		ft_putchar_fd(((n % 10) + '0'), fd);
	}
}
