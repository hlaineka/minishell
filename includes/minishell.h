/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 13:54:45 by hlaineka          #+#    #+#             */
/*   Updated: 2020/10/05 18:22:49 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/ft_printf.h"
#include "../libft/includes/libft.h"
#include "../programs/ft_ls/includes/ft_ls.h"
#include <termios.h>

typedef struct		s_editor
{
	struct termios	*original_termios;
	t_list			*command_buf;
	t_list			*print_buf;
	int				screenrows;
	int				screencols;
	int				cursorrow;
	int				cursorcol;
}					t_editor;

typedef struct		s_string
{
	char	*string;
	int		len;
}					t_string;