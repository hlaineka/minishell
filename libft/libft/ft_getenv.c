/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 11:19:46 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:27:26 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** returns the corresponding value to name string from the envp strarray given
** as a parameter. if envp_pointer is NULL or if the name is not found in the
** envp_pointer, NULL is returned.
*/

char	*ft_getenv(char **envp_pointer, char *name)
{
	char	**temp_strarray;
	char	*temp;
	char	*returnable;
	int		i;
	int		i_of_equal;

	i = 0;
	temp_strarray = envp_pointer;
	returnable = NULL;
	while (temp_strarray && temp_strarray[i])
	{
		i_of_equal = ft_str_find_c(temp_strarray[i], '=');
		if (i_of_equal > -1)
		{
			temp = ft_strsub(temp_strarray[i], 0, i_of_equal);
			if (ft_strequ(temp, name))
				returnable = ft_strsub(temp_strarray[i], i_of_equal + 1,
					ft_strlen(temp_strarray[i]) - i_of_equal);
			free(temp);
		}
		i++;
	}
	return (returnable);
}
