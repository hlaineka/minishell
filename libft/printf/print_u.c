/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 12:24:57 by hlaineka          #+#    #+#             */
/*   Updated: 2020/05/22 09:48:23 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*uint_width(char *string, int width, t_tags *command)
{
	char	*returnable;
	int		i;

	i = 0;
	if ((int)ft_strlen(string) < width)
	{
		if (command->flag_zero && !command->flag_minus
				&& command->precision == -1)
			returnable = ft_strset('0', width);
		else
			returnable = ft_strset(' ', width);
		if (command->flag_minus)
			ft_strpaste(returnable, string);
		else if (command->flag_zero)
			uint_width_flag_zero(returnable, string, command);
		else
			ft_strpaste(&returnable[width - ft_strlen(string)], string);
	}
	else
		returnable = ft_strdup(string);
	free(string);
	return (returnable);
}

static char	*uint_precision(char *string, t_tags *command)
{
	char	*returnable;

	if (ft_strequ(string, "0") && command->precision == 0)
		returnable = ft_strnew(0);
	else if (ft_strequ(string, "+0") && command->precision == 0)
		returnable = ft_strdup("+");
	else if ((int)ft_strlen(string) <= command->precision)
	{
		returnable = ft_strset('0', command->precision);
		ft_strpaste_digits(&returnable[ft_strlen(returnable)
				- ft_strlen(string)], string);
		if (!ft_isdigit(string[0]))
			returnable = ft_char_str_join(string[0], returnable);
	}
	else
		returnable = ft_strdup(string);
	free(string);
	return (returnable);
}

static char	*uint_editor(char *printable, t_tags *command, int original)
{
	if (command->flag_plus && original >= 0)
		printable = ft_strjoin_frees2("+", printable);
	if (command->precision != -1)
		printable = uint_precision(printable, command);
	if (command->width != -1)
		printable = uint_width(printable, command->width, command);
	return (printable);
}

uintmax_t	read_uint(t_tags *command, va_list *source)
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

int			print_u(t_tags *command, va_list *source)
{
	char		*printable;
	uintmax_t	aquired;
	int			returnable;

	aquired = read_uint(command, source);
	printable = ft_itoa_uint(aquired, 10);
	printable = uint_editor(printable, command, aquired);
	ft_putstr(printable);
	returnable = ft_strlen(printable);
	free(printable);
	return (returnable);
}
