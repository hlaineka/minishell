/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner_helpers2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:59:06 by helvi             #+#    #+#             */
/*   Updated: 2021/02/15 16:54:45 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
** Helper function to make replace_tilde() shorter..
*/

char	*replacer(char *orig, char *env_str, int *i, t_editor *info)
{
	char	*returnable;
	char	*temp;

	temp = ft_getenv(info->envp_pointer, env_str);
	returnable = ft_replc(orig, *i, temp);
	*i = *i + ft_strlen(temp) - 1;
	free(temp);
	return (returnable);
}
