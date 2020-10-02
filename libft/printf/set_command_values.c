/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_command_values.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 10:38:52 by hlaineka          #+#    #+#             */
/*   Updated: 2020/05/22 09:48:30 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	set_flag(t_tags *command, char flag)
{
	if (flag == '0')
		command->flag_zero = TRUE;
	else if (flag == '-')
		command->flag_minus = TRUE;
	else if (flag == '+')
		command->flag_plus = TRUE;
	else if (flag == ' ')
		command->flag_space = TRUE;
	else if (flag == '#')
		command->flag_hash = TRUE;
}

void	set_width(t_tags *command, char c, va_list *source)
{
	char	character[2];

	if (c == '*')
	{
		command->width = va_arg(*source, int);
		command->width_address = TRUE;
		if (command->width < 0)
		{
			command->width = -1 * command->width;
			command->flag_minus = TRUE;
		}
	}
	else
	{
		if (command->width_address == TRUE)
		{
			command->width = 0;
			command->width_address = FALSE;
		}
		character[0] = c;
		character[1] = '\0';
		if (command->width == -1)
			command->width = 0;
		command->width = command->width * 10 + ft_atoi(character);
	}
}

void	set_wildcard_precision(t_tags *command, va_list *source)
{
	command->precision = va_arg(*source, int);
	command->precision_address = TRUE;
	if (command->precision < 0)
	{
		command->precision = -1 * command->precision;
		if (command->precision > command->width)
			command->precision = command->width;
		command->flag_minus = TRUE;
	}
}

void	set_precision(t_tags *command, char c, va_list *source)
{
	char	character[2];

	if (c == '.')
	{
		command->precision = 0;
		return ;
	}
	if (c == '*')
		set_wildcard_precision(command, source);
	else
	{
		if (command->precision_address == TRUE)
		{
			command->precision = 0;
			command->precision_address = FALSE;
		}
		character[0] = c;
		character[1] = '\0';
		if (command->precision == -1)
			command->precision = 0;
		command->precision = command->precision * 10 + ft_atoi(character);
	}
}

void	set_length(t_tags *command, char c)
{
	if (c == 'h')
		if (command->length_h)
		{
			command->length_hh = TRUE;
			command->length_h = FALSE;
		}
		else
			command->length_h = TRUE;
	else if (c == 'l')
		if (command->length_l)
		{
			command->length_ll = TRUE;
			command->length_l = FALSE;
		}
		else
			command->length_l = TRUE;
	else
		command->length_lll = TRUE;
}
