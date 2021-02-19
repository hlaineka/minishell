/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:24:17 by helvi             #+#    #+#             */
/*   Updated: 2021/02/19 11:23:54 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** reads and handles env parameters. This function is called when env
** reads its argv and encounters a - character. -i empties the temp
** envp variable, and -u deletes the given value.
*/

int		handle_env_parameter(char **argv, int *i, char ***temp_envp)
{
	if (argv[*i][1] == 'i')
	{
		ft_strarray_free(*temp_envp);
		*temp_envp = NULL;
		if (!argv[*i + 1])
			return (0);
	}
	else if (argv[*i][1] == 'u')
	{
		if (!argv[*i + 1])
			return (print_envusage(1, 'u'));
		*i = *i + 1;
		*temp_envp = ft_envhelper_unset(argv[*i], *temp_envp);
		if (!argv[*i + 1])
		{
			print_env(*temp_envp);
			return (0);
		}
	}
	else
		return (print_envusage(2, argv[*i][1]));
	return (1);
}

/*
** When env goes through the argv it has been given, if it encounters
** a = character in an argument, this function is called. Searches through
** the env pointer, and adds the value by calling add_str_to_env.
*/

int		handle_new_env(char **argv, int i, char ***temp_envp)
{
	char	*temp;

	temp = ft_strsub(argv[i], 0, ft_str_find_c(argv[i], '='));
	*temp_envp = add_str_to_env(*temp_envp, argv[i],
				getenv_index(*temp_envp, temp));
	free(temp);
	if (!argv[i + 1])
		return (print_env(*temp_envp));
	return (1);
}

/*
** Helper functions to make ft_env() shorter. Prints the error message
** to stderr and frees temp_envp and temp_argv to avoid leaks.
*/

int		env_command_nf(char **temp_envp, char **temp_argv)
{
	ft_printf("%rcommand not found: %s\n", temp_argv[0]);
	env_free(temp_envp, temp_argv, NULL);
	return (1);
}

/*
** Helper function to make ft_env() shorter. Frees the temp_env and
** temp_argv given as parameter.
*/

int		env_free(char **temp_envp, char **temp_argv, char *str)
{
	if (temp_envp)
		ft_strarray_free(temp_envp);
	if (temp_argv)
		ft_strarray_free(temp_argv);
	if (str)
		ft_free(str);
	return (1);
}
