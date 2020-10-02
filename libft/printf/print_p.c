/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 12:24:38 by hlaineka          #+#    #+#             */
/*   Updated: 2020/05/22 09:48:12 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_strpaste_pointer(char *dest, char *src)
{
	int		i;
	int		w;

	i = 0;
	w = 0;
	while (src[i] != '\0')
		i++;
	while (dest[w] != '\0')
		w++;
	while (i >= 0 && w >= 0 && src[i] != 'x')
		dest[w--] = src[i--];
}

static char	*pointer_width(char *string, int width, t_tags *command)
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

static char	*pointer_precision(char *string, t_tags *command)
{
	char	*returnable;

	if (ft_strlen(string) < 14)
	{
		if (ft_strequ(string, "0x0") && command->precision == 0)
		{
			free(string);
			return (ft_strdup("0x"));
		}
		else if ((int)ft_strlen(string) < command->precision)
			returnable = ft_strset('0', command->precision);
		else
			returnable = ft_strset('0', ft_strlen(string));
		ft_strpaste_pointer(returnable, string);
		returnable = ft_strjoin_frees2("0x", returnable);
	}
	else
		returnable = ft_str_realloc(string, 0, ft_strlen(string));
	return (returnable);
}

static char	*pointer_editor(char *printable, t_tags *command)
{
	if (command->width != -1)
		printable = pointer_width(printable, command->width, command);
	if (command->precision != -1)
		printable = pointer_precision(printable, command);
	return (printable);
}

int			print_p(t_tags *command, va_list *source)
{
	void	*pointer;
	char	*printable;
	int		returnable;

	pointer = va_arg(*source, void*);
	printable = ft_itoa_hexa((uintmax_t)(pointer));
	printable = ft_strjoin_frees2("0x", printable);
	printable = pointer_editor(printable, command);
	ft_putstr(printable);
	returnable = ft_strlen(printable);
	free(printable);
	return (returnable);
}
