/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 10:02:18 by hlaineka          #+#    #+#             */
/*   Updated: 2020/05/22 09:48:04 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*float_width(char *string, int width, t_tags *command)
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
			float_width_flag_zero(returnable, string, command);
		else
			ft_strpaste(&returnable[width - ft_strlen(string)], string);
	}
	else
		returnable = ft_strdup(string);
	free(string);
	return (returnable);
}

static char	*float_precision(char *string, t_tags *command)
{
	char	*returnable;

	if (ft_strequ(string, "+0") && command->precision == 0)
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

static char	*add_floatspace(char *string, t_tags *command)
{
	char	*returnable;

	if (ft_isdigit(string[0]))
	{
		if (command->flag_zero)
			returnable = ft_strjoin_frees2("0", string);
		else
			returnable = ft_strjoin_frees2(" ", string);
	}
	else
		return (string);
	return (returnable);
}

static char	*float_editor(char *printable, t_tags *command)
{
	printable = ft_trim(printable, command);
	if (command->flag_plus && command->positive_value)
		printable = ft_strjoin_frees2("+", printable);
	if (command->flag_space && command->positive_value)
		printable = add_floatspace(printable, command);
	if (command->precision != -1)
		printable = float_precision(printable, command);
	if (command->width != -1)
		printable = float_width(printable, command->width, command);
	return (printable);
}

int			print_f(t_tags *command, va_list *source)
{
	char		*printable;
	long double	aquired;
	int			returnable;

	aquired = read_float(command, source);
	if (aquired >= 0)
		command->positive_value = TRUE;
	aquired = ft_round(aquired, command);
	printable = ft_itoa_float(aquired);
	printable = float_editor(printable, command);
	returnable = ft_strlen(printable);
	ft_putstr(printable);
	free(printable);
	return (returnable);
}
