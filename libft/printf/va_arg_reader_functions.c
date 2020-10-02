/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg_reader_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:27:38 by hlaineka          #+#    #+#             */
/*   Updated: 2020/05/22 09:48:34 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

uintmax_t		read_octal(t_tags *command, va_list *source)
{
	if (command->length_hh)
		return (unsigned char)va_arg(*source, uintmax_t);
	else if (command->length_h)
		return (unsigned short int)va_arg(*source, uintmax_t);
	else if (command->length_l)
		return (unsigned long int)va_arg(*source, uintmax_t);
	else if (command->length_ll)
		return (unsigned long long int)va_arg(*source, uintmax_t);
	else
		return (unsigned int)va_arg(*source, uintmax_t);
}

long long int	read_int(t_tags *command, va_list *source)
{
	long long int	returnable;

	if (command->length_hh)
		returnable = (signed char)va_arg(*source, int);
	else if (command->length_h)
		returnable = (short int)va_arg(*source, int);
	else if (command->length_l)
		returnable = va_arg(*source, long int);
	else if (command->length_ll)
		returnable = va_arg(*source, long long int);
	else
		returnable = va_arg(*source, int);
	returnable = (long long int)returnable;
	return (returnable);
}

long double		read_float(t_tags *command, va_list *source)
{
	long double	returnable;

	if (command->length_lll)
		returnable = va_arg(*source, long double);
	else
		returnable = (long double)va_arg(*source, double);
	return (returnable);
}

uintmax_t		read_hexa(t_tags *command, va_list *source)
{
	if (command->length_hh)
		return (unsigned char)va_arg(*source, uintmax_t);
	else if (command->length_h)
		return (unsigned short int)va_arg(*source, uintmax_t);
	else if (command->length_l)
		return (unsigned long int)va_arg(*source, uintmax_t);
	else if (command->length_ll)
		return (unsigned long long int)va_arg(*source, uintmax_t);
	else
		return (unsigned int)va_arg(*source, uintmax_t);
}
