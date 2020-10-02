/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_trim_and_round.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 10:25:02 by hlaineka          #+#    #+#             */
/*   Updated: 2020/05/22 09:47:36 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char			*ft_trim(char *str, t_tags *command)
{
	int		i;
	int		w;
	char	*returnable;

	if (command->precision != -1)
		i = command->precision;
	else
		i = 6;
	w = 0;
	while (str[w] != '.')
		w++;
	i = i + w + 1;
	if (command->precision == 0 && !command->flag_hash)
		i--;
	while (str[w] != '\0' && w < i)
		w++;
	returnable = ft_str_realloc(str, 0, w);
	return (returnable);
}

long double		ft_round(long double number, t_tags *command)
{
	long double	returnable;
	int			i;
	long double	multiplier;

	multiplier = .5;
	if (command->precision != -1)
		i = command->precision;
	else
		i = 6;
	while (i > 0)
	{
		multiplier = multiplier / 10;
		i--;
	}
	if (number >= 0)
		returnable = number + multiplier;
	else
		returnable = number - multiplier;
	return (returnable);
}
