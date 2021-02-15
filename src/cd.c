/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:24:50 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/15 17:21:40 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
** Functions used to execute the build in command cd. Helper functions can also
** be found on cd_helpers.c file. The build in cd command handles relative and
** absolute paths, as well as extensions $ and ~, and also cd without parameters
** cd - and env variable CDPATH.
*/

/*
** A manual error handling for cd path checkup. Uses c function access(),
** lstat() and stat(). Handles errors "Filename too long", "No such file or
** directory", "Too many symbolic links encountered" (this cd does not handle
** any..), "Not a directory" and "Permission denied". All the rest of the
** errors will be handled by lstat fail, stat fail or chdir fail (the latter
** checked in ft_cd() function) because those are too random to produce and
** test.
*/

static int	check_path_errors(char *path)
{
	struct stat	*stat_buf;
	int			returnable;

	returnable = 1;
	stat_buf = (struct stat*)malloc(sizeof(struct stat));
	if (ft_strlen(path) >= 255)
		returnable = (print_errorstr(36, "cd", path));
	else if (-1 == lstat(path, stat_buf))
	{
		if (0 != access(path, F_OK))
			returnable = (print_errorstr(2, "cd", path));
		else
			returnable = (print_errorstr(41, "cd: lstat fail\n", path));
	}
	else if (S_ISLNK(stat_buf->st_mode))
		returnable = (print_errorstr(40, "cd", path));
	else if (-1 == stat(path, stat_buf))
		returnable = (print_errorstr(41, "cd: stat fail\n", path));
	else if (!S_ISDIR(stat_buf->st_mode))
		returnable = (print_errorstr(20, "cd", path));
	else if (0 != access(path, X_OK))
		returnable = (print_errorstr(13, "cd", path));
	ft_free(stat_buf);
	return (returnable);
}

/*
** create_new_path() adds a new directory to the allready handled ones,
** and checks the new path to check_path_errors() to be validated.
*/

static int	create_new_path(char **absolute_path, char *new_dir)
{
	char	*temp_path;

	if (ft_strequ(new_dir, "."))
		return (1);
	else if (ft_strequ(new_dir, ".."))
	{
		temp_path = ft_strsub(*absolute_path, 0,
				ft_str_rfind_c(*absolute_path, '/'));
		free(*absolute_path);
		*absolute_path = temp_path;
	}
	else
	{
		temp_path = ft_strjoin3(*absolute_path, "/", new_dir);
		free(*absolute_path);
		*absolute_path = temp_path;
	}
	if (-1 == (check_path_errors(*absolute_path)))
		return (-1);
	return (1);
}

/*
** check_path() divides the earlier created absolute path in to a strarr with
** each folder as its own string. After this starts to create a path in a
** while loop by adding one path at a time with create_new_path, that send
** this path to check_path_errors to be validated.
*/

static int	check_path(char **path, char **envp)
{
	char		**directories;
	int			i;
	char		*absolute_path;
	char		*temp_path;

	temp_path = NULL;
	if (!(temp_path = get_cd_path(*path, envp)))
		return (-1);
	absolute_path = ft_strnew(1);
	directories = ft_strsplit(temp_path, '/');
	ft_free(temp_path);
	i = 0;
	while (directories[i])
	{
		if (-1 == (create_new_path(&absolute_path, directories[i++])))
		{
			ft_free(absolute_path);
			ft_strarray_free(directories);
			return (-1);
		}
	}
	ft_free(*path);
	*path = absolute_path;
	ft_strarray_free(directories);
	return (0);
}

/*
** cd_home() creates a path for cd in case the argument list for cd is
** empty.
*/

static int	cd_home(char **envp, char **path)
{
	char	*homedir;

	homedir = ft_getenv(envp, "HOME");
	if (!homedir)
	{
		ft_printf("%rcd: HOME not set\n");
		return (-1);
	}
	*path = ft_strdup(homedir);
	ft_free(homedir);
	return (0);
}

/*
** The main function of the cd build in. Checks that the amount of parameters
** is right and sends the path given as an argument to check_path to be checked
** adn then changes the dir with c function chdir, and updates the PWD and
** OLDPWD values in the env variable with add_cdpath_env()
*/

int			ft_cd(char **argv, char ***envp)
{
	char		*path;

	path = NULL;
	if (ft_array_length(argv) > 2)
		return (cd_errorfree("cd: too many arguments\n", NULL));
	if (ft_array_length(argv) == 1)
	{
		if (-1 == cd_home(*envp, &path))
			return (1);
	}
	else
		path = ft_strdup(argv[1]);
	if (-1 == (check_path(&path, *envp)))
		return (cd_errorfree(NULL, path));
	if (-1 == (chdir(path)))
	{
		print_errorstr(41, "cd: chdir fail\n", path);
		return (cd_errorfree(NULL, path));
	}
	add_cdpath_env(path, envp);
	ft_free(path);
	return (1);
}
