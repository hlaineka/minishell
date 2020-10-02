/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 15:06:23 by hlaineka          #+#    #+#             */
/*   Updated: 2020/05/22 09:47:48 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	int_width_flag_zero(char *returnable, char *string, t_tags *command)
{
	int		i;

	i = 0;
	ft_strpaste_digits(&returnable[command->width - ft_strlen(string)], string);
	while (returnable[i] == ' ')
		i++;
	if (i > 0)
		i--;
	if (!command->positive_value)
		returnable[i] = '-';
	if (command->positive_value && command->flag_plus)
		returnable[i] = '+';
	if (command->positive_value && command->flag_space && i == 0)
		returnable[i] = ' ';
}

void	float_width_flag_zero(char *returnable, char *string, t_tags *command)
{
	int		i;

	i = 0;
	ft_strpaste_digits(&returnable[command->width - ft_strlen(string)], string);
	while (returnable[i] == ' ')
		i++;
	if (i > 0)
		i--;
	if (!command->positive_value)
		returnable[i] = '-';
	if (command->positive_value && command->flag_plus)
		returnable[i] = '+';
	if (command->positive_value && command->flag_space && i == 0)
		returnable[i] = ' ';
}

void	uint_width_flag_zero(char *returnable, char *string, t_tags *command)
{
	int		i;

	i = 0;
	ft_strpaste_digits(&returnable[command->width - ft_strlen(string)], string);
	while (returnable[i] == ' ')
		i++;
	if (i > 0)
		i--;
	if (command->positive_value && command->flag_plus)
		returnable[i] = '+';
}

char	*hexa_upperalpha(char *string)
{
	int		i;
	char	*returnable;

	returnable = ft_strnew(ft_strlen(string));
	i = 0;
	while (string[i] != '\0')
	{
		if (ft_isalpha(string[i]))
			returnable[i] = ft_toupper(string[i]);
		else
			returnable[i] = string[i];
		i++;
	}
	free(string);
	return (returnable);
}

int		is_specifier(char c)
{
	if (c == 's' || c == 'c' || c == 'p' || c == 'd'
	|| c == 'i' || c == 'o' || c == 'u' || c == 'x'
	|| c == 'X' || c == '%' || c == 'f')
		return (TRUE);
	return (FALSE);
}
