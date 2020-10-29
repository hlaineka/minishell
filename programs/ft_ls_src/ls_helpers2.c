/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_helpers2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 18:53:40 by hlaineka          #+#    #+#             */
/*   Updated: 2020/09/29 11:10:48 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

char	*search_path(char *directory_name)
{
	char	*returnable;
	char	*temp_str;
	int		i;
	int		w;

	if (!directory_name)
		return (NULL);
	returnable = NULL;
	if (ft_strlast(directory_name) == '/')
		temp_str = ft_strsub(directory_name, 0, ft_strlen(directory_name) - 1);
	else
		temp_str = ft_strdup(directory_name);
	i = 0;
	w = 0;
	while (temp_str[i])
	{
		if (temp_str[i] == '/')
			w = i;
		i++;
	}
	if (w)
		returnable = ft_strsub(temp_str, 0, w + 1);
	free(temp_str);
	return (returnable);
}

char	*check_name(char *name)
{
	char			*new_name;

	new_name = NULL;
	if (ft_strlast(name) != '/')
		new_name = ft_str_char_join('/', name);
	else
		new_name = ft_strdup(name);
	return (new_name);
}
