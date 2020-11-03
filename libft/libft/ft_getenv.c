/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 11:19:46 by hlaineka          #+#    #+#             */
/*   Updated: 2020/11/02 11:34:32 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_getenv(char **envp_pointer, char *name)
{
	char	**temp_strarray;
	char	*temp;
	char	*cap_name;
	char	*returnable;
	int		i;

	i = 0;
	temp_strarray = envp_pointer;
	returnable = NULL;
	cap_name = ft_str_toupper(name);
	while(temp_strarray[i])
	{
		temp = ft_strsub(temp_strarray[i], 0, ft_str_find_c(temp_strarray[i], '='));
		if (ft_strequ(temp, cap_name))
			returnable = ft_strsub(temp_strarray[i], ft_str_find_c(temp_strarray[i], '=') + 1, ft_strlen(temp_strarray[i]));
		free(temp);
		i++;
	}
	free(cap_name);
	return (returnable);
}