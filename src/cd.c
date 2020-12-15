/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:24:50 by hlaineka          #+#    #+#             */
/*   Updated: 2020/12/01 16:59:19 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_cd(char **argv, t_editor *info){

	if (ft_array_length(argv) > 3){
		ft_putstr_fd("cd: too many arguments", 2);
		return -1;
	}
	if (info)
		return (0);
	else return (1);
}