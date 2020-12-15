/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 12:23:57 by hlaineka          #+#    #+#             */
/*   Updated: 2020/12/01 16:55:28 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*int_width(char *string, int width, t_tags *command)
{
	char	*returnable;

	if ((int)ft_strlen(string) < width)
	{
		if (command->flag_zero && !command->flag_minus &&
				command->precision == -1)
			returnable = ft_strset('0', width);
		else
			returnable = ft_strset(' ', width);
		if (command->flag_minus)
			ft_strpaste(returnable, string);
		else if (command->flag_zero)
			int_width_flag_zero(returnable, string, command);
		else
			ft_strpaste(&returnable[width - ft_strlen(string)], string);
	}
	else
		returnable = ft_strdup(string);
	free(string);
	return (returnable);
}

static char	*int_precision(char *string, t_tags *command)
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

char		*add_intspace(char *string)
{
	char	*returnable;

	if (ft_isdigit(string[0]))
		returnable = ft_strjoin_frees2(" ", string);
	else
		return (string);
	return (returnable);
}

static char	*int_editor(char *printable, t_tags *command)
{
	if (command->flag_plus && command->positive_value)
		printable = ft_strjoin_frees2("+", printable);
	if (command->flag_space && command->positive_value)
		printable = add_intspace(printable);
	if (command->precision != -1)
		printable = int_precision(printable, command);
	if (command->width != -1)
		printable = int_width(printable, command->width, command);
	return (printable);
}

int			print_d(t_tags *command, va_list *source)
{
	char			*printable;
	long long int	aquired;
	int				returnable;

	aquired = read_int(command, source);
	if (aquired >= 0)
		command->positive_value = TRUE;
	printable = ft_itoa_base(aquired, 10);
	printable = int_editor(printable, command);
	returnable = ft_strlen(printable);
	ft_putstr_fd(printable, command->flag_fd);
	free(printable);
	return (returnable);
}
