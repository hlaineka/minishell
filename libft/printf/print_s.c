/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 12:24:47 by hlaineka          #+#    #+#             */
/*   Updated: 2020/12/01 16:57:22 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*string_width(char *string, int width, t_tags *command)
{
	char	*returnable;

	if ((int)ft_strlen(string) < width)
	{
		returnable = ft_strset(' ', width);
		if (command->flag_minus)
			ft_strpaste(returnable, string);
		else
			ft_strpaste(&returnable[width - ft_strlen(string)], string);
	}
	else
		returnable = ft_strdup(string);
	free(string);
	return (returnable);
}

static char	*string_precision(char *string, int precision)
{
	char	*returnable;

	if ((int)ft_strlen(string) > precision)
		returnable = ft_str_realloc(string, 0, precision);
	else
	{
		returnable = ft_strdup(string);
		free(string);
	}
	return (returnable);
}

static char	*string_editor(char *printable, t_tags *command)
{
	if (command->precision != -1)
		printable = string_precision(printable, command->precision);
	if (command->width != -1)
		printable = string_width(printable, command->width, command);
	return (printable);
}

int			print_s(t_tags *command, va_list *source)
{
	char	*printable;
	char	*aquired;
	int		returnable;

	aquired = NULL;
	aquired = va_arg(*source, char*);
	if (aquired == NULL)
		printable = ft_strdup("(null)");
	else
		printable = ft_strdup(aquired);
	printable = string_editor(printable, command);
	ft_putstr_fd(printable, command->flag_fd);
	returnable = ft_strlen(printable);
	free(printable);
	return (returnable);
}
