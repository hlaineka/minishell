/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 10:38:16 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/19 11:35:36 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** searches the source string for newline or end of string. If newline is
** not found, returns 0. If newline is found, copies source string until
** the newline to the end of destination string, and removes all data until
** newline from source string. Uses ft_str_realloc to string reallocation
*/

static int		search_newline(char **dest, char **src)
{
	int		i;

	i = 0;
	if (!src || !*src || src[0][0] == '\0')
		return (0);
	while (src[0][i] != '\0' && src[0][i] != '\n')
		i++;
	if (src[0][i] == '\n')
	{
		if (!*dest)
			*dest = ft_strsub(*src, 0, i);
		else
			*dest = ft_str_realloc(*src, 0, i);
		*src = ft_str_realloc(*src, i + 1, ft_strlen(*src));
		return (1);
	}
	return (0);
}

/*
** reads the fd given as parameter and writes a string from the input that
** is until newline or EOF to the parameter line. The newline characters are
** nor included in line. Returns one every time it writes a line to line and
** zero ones the EOF has been reached.
*/

int				get_next_line(const int fd, char **line)
{
	static char	*fds[FD_LIMIT];
	char		buf[BUFF_SIZE];
	int			bytes;
	int			returnable;

	if (fd < 0 || fd > FD_LIMIT || !line)
		return (-1);
	*line = NULL;
	bytes = 0;
	while ((returnable = search_newline(line, &fds[fd])) == 0
		&& (bytes = read(fd, buf, BUFF_SIZE)) > 0)
		ft_dynamic_string(&fds[fd], buf, bytes);
	if (bytes < 0)
		return (-1);
	if (bytes == 0 && *line == NULL && (fds[fd] == NULL || fds[fd][0] == '\0'))
		return (0);
	if (bytes == 0 && returnable == 0 && fds[fd][0] != '\0')
	{
		*line = ft_strdup(fds[fd]);
		fds[fd] = ft_strdup("\0");
		return (1);
	}
	return (1);
}
