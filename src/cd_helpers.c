/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:07:30 by helvi             #+#    #+#             */
/*   Updated: 2021/02/18 14:29:23 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
** Helper function to make get_cd_path() shorter. Gets the right path
** from env variable list to create a absolute path.
*/

static char	*cd_replacer(char **envp, char *name, char *path)
{
	char	*temp;
	char	*returnable;

	if (ft_strequ(name, "PWD"))
		temp = get_pwd(envp);
	else
		temp = ft_getenv(envp, name);
	returnable = ft_strjoin3(temp, "/", path);
	ft_free(temp);
	return (returnable);
}

/*
** changes a relative path to absolute path
*/

char		*get_cd_path(char *path, char **envp)
{
	char	*returnable;

	if (path[0] == '/' || path[0] == '~')
		returnable = ft_strdup(path);
	else if (path[0] == '-')
	{
		if (-1 == getenv_index(envp, "OLDPWD"))
		{
			ft_putstr_fd("cd: OLDPWD not set\n", 2);
			return (NULL);
		}
		returnable = ft_getenv(envp, "OLDPWD");
	}
	else if (-1 != getenv_index(envp, "CDPATH"))
		returnable = cd_replacer(envp, "CDPATH", path);
	else
		returnable = cd_replacer(envp, "PWD", path);
	return (returnable);
}

/*
** updates the envp variable list after the ft_cd() has changed the dir
** with chdir. The new path is saved to PWD and the previous value of PWD to
** OLDPWD.
*/

int			add_cdpath_env(char *path, char ***envp)
{
	char		*temp;
	char		*temp2;
	char		*temp3;

	temp3 = ft_strjoin3("PWD", "=", path);
	temp2 = ft_getenv(*envp, "PWD");
	temp = ft_strjoin3("OLDPWD", "=", temp2);
	*envp = add_str_to_env(*envp, temp, getenv_index(*envp, "OLDPWD"));
	*envp = add_str_to_env(*envp, temp3, getenv_index(*envp, "PWD"));
	ft_free(temp);
	ft_free(temp2);
	ft_free(temp3);
	return (1);
}

/*
** A helper function for ft_cd() to make the function shorter. When exiting
** the ft_cd() this function can print an error message and free a str when
** necessary.
*/

int			cd_errorfree(char *message, char *tofree)
{
	if (message)
		ft_putstr_fd(message, 2);
	if (tofree)
		ft_free(tofree);
	return (1);
}

char		*prev_dir(char *absolute_path)
{
	char	*returnable;

	returnable = NULL;
	returnable = ft_strsub(absolute_path, 0,
					ft_str_rfind_c(absolute_path, '/'));
	if (!returnable || returnable[0] == '\0')
	{
		ft_free(returnable);
		returnable = ft_strdup("/");
	}
	return (returnable);
}
