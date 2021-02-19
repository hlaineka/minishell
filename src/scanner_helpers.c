/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helvi <helvi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 09:11:47 by helvi             #+#    #+#             */
/*   Updated: 2021/02/19 11:24:46 by helvi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Helper function to replace_tilde to make it shorter. Prints an error
** message to stderr, frees the temp_str and returns -1 to exit scanner.
*/

static int	tilde_error(char **temp_str, char *name)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(" not set\n", 2);
	ft_free(*temp_str);
	return (-1);
}

/*
** When the check_replacement() function finds a ~ (tilde), it calls for
** replace_tilde() to do the substitution. ~ replaces the character with
** the environment value $HOME, ~- is replaced with $OLDPWD and ~+ with PWD.
** if the env variable is not set, prints an error message and returns -1
*/

int			replace_tilde(char **temp_str, int *i, t_editor *info)
{
	char	*temp;

	if (temp_str[0][*i + 1] && temp_str[0][*i + 1] == '-')
	{
		if (-1 == getenv_index(info->envp_pointer, "OLDPWD"))
			return (tilde_error(temp_str, "OLDPWD"));
		temp = replacer(*temp_str, "OLDPWD", i, info);
	}
	else if (temp_str[0][*i + 1] && temp_str[0][*i + 1] == '+')
	{
		if (-1 == getenv_index(info->envp_pointer, "PWD"))
			return (tilde_error(temp_str, "PWD"));
		temp = replacer(*temp_str, "PWD", i, info);
	}
	else
	{
		if (-1 == getenv_index(info->envp_pointer, "HOME"))
			return (tilde_error(temp_str, "HOME"));
		temp = replacer(*temp_str, "HOME", i, info);
	}
	free(*temp_str);
	*temp_str = temp;
	return (0);
}

/*
** When the check_replacement() function finds a $ (dollar) sign, it calls
** replace_dollar() to do the replacement. This function recursively calls
** the read_string function to get the next value (temp3), and searches the
** envp pointer for a variable with that name (temp). It then removes the
** variable name (temp3) from the temp_str where the original string is stored
** and saves it (temp2). After that the $ sign is substituted with the value
** (temp3). The new string is then saved to temp_str. Also the value of i is
** updated, that is the index with witch the check_replacement goes through
** the temp_str. returnable is a value that is passed down to string_scanner()
** and it indexes the original string.
*/

int			replace_dollar(char **temp_str, int *i, t_editor *info)
{
	int		returnable;
	char	*temp;
	char	*temp2;
	char	*temp3;

	read_string(&temp_str[0][*i + 1], &temp3, info);
	temp = ft_getenv(info->envp_pointer, temp3);
	temp2 = ft_strstr_remove(*temp_str, temp3);
	returnable = ft_strlen(temp3);
	free(temp3);
	temp3 = ft_replc(temp2, *i, temp);
	*i = *i + ft_strlen(temp) - 1;
	ft_free(temp);
	free(*temp_str);
	*temp_str = ft_strdup(temp3);
	free(temp2);
	free(temp3);
	return (returnable);
}

/*
** Replacements for esc character, called by remove_escchars().
*/

int			replace_escchar(int c)
{
	if (c == '0')
		return ('\0');
	if (c == 'n')
		return ('\n');
	if (c == 'r')
		return ('\r');
	if (c == 't')
		return ('\t');
	if (c == 'b')
		return ('\b');
	if (c == 'f')
		return ('\f');
	if (c == 'v')
		return ('\v');
	if (c == 'r')
		return ('\r');
	return (c);
}

/*
** Helper function to free the t_command structure.
*/

void		free_commands(t_command *command)
{
	t_command	*next_command;

	while (command)
	{
		next_command = command->next_command;
		ft_strarray_free(command->command_argv);
		ft_free(command);
		command = next_command;
	}
}
