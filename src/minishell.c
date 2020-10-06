/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 13:37:18 by hlaineka          #+#    #+#             */
/*   Updated: 2020/10/06 14:29:37 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	enable_rawmode(t_editor *info)
{
	struct termios	raw;
	struct termios	*original_termios;

	original_termios = (struct termios*)malloc(sizeof(struct termios));
	tcgetattr(STDIN_FILENO, info->original_termios);
	tcgetattr(STDIN_FILENO, &raw);
	raw.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);

}

void	disable_rawmode(struct termios *original_termios)
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, original_termios);
}

void	exitprocess(t_editor *info)
{
	disable_rawmode(info->original_termios);
	exit (0);
}

char	read_key_press()
{
	char	returnable;

	read(STDIN_FILENO, &returnable, 1);
	//if (ft_iscntrl(returnable))
	//	ft_printf("%d", returnable);
	//if (ft_isprint(returnable))
	//	ft_printf("%c", returnable);
	return(returnable);
}

void	clear_screen()
{
	write(STDOUT_FILENO, "\x1b[2J", 4);
	write(STDOUT_FILENO, "\x1b[H", 3);
}

void	print_screen(t_editor *info, char *command)
{
	t_list *temp;

	clear_screen();
	temp = info->print_buf;
	while (temp)
	{
		ft_printf((char*)temp->content);
		temp = temp->next;
	}
	ft_printf(command);
}

int	check_keypress(char c, char **command, t_editor *info)
{
	char	*temp;
	int		i;

	if (ft_isprint(c))
		temp = ft_str_char_join(c, *command);
	else if (c == 127 && (ft_strlen(*command) <= 0))
		temp = ft_strnew(1);
	else if (c == 127 && (ft_strlen(*command) > 0))
	{	
		temp = ft_strsub(*command, 0, ft_strlen(*command) - 1);
		print_screen(info, temp);
	}
	else if (c == 27)
	{
		i = c * 100 + read_key_press();
		i = i * 100 + read_key_press();
		if (i == UP)
			ft_printf("up");
		if (i == DOWN)
			ft_printf("down");
		if (i == LEFT)
			ft_printf("left");
		if (i == RIGHT)
			ft_printf("right");
		temp = ft_strdup(*command);
		c = 0;
	}
	else
		temp = ft_strdup(*command);
	free(*command);
	*command = ft_strdup(temp);
	free(temp);
	if (ft_isprint(c))
		ft_putchar(c);
	return(0);
}

void	process_key_press(t_editor *info)
{
	char		c;
	char		*command;
	int			i;
	t_list		*new_command;
	t_list		*temp_list;
	char		*temp;

	i = 0;
	command = NULL;
	while (!command || !ft_strequ(command, "exit"))
	{
		free(command);	
		command = ft_strnew(1);
		ft_lstnewtoend("$>", ft_strlen("$>"), &(info->print_buf));
		ft_putstr("$>");
		temp_list = info->command_buf;
		while ((c = read_key_press()) != 10)
		{
			i = check_keypress(c, &command, info);
			if (i == 127 && temp_list)
				print_screen(info, (char*)temp_list->content);
		}
		if (command)
		{
			ft_lstnewtoend(command, ft_strlen(command), &(info->print_buf));
			temp = ft_strjoin3("\n", command, "\n");
			ft_lstnewtoend(temp, ft_strlen(temp), &(info->print_buf));
			new_command = ft_lstnew(command, ft_strlen(command));
			ft_lstadd(&(info->command_buf), new_command);
			ft_printf(temp);
			free(temp);
		}
	}
}

int		main(void)
{
	t_editor	*info;
	
	info = (t_editor*)malloc(sizeof(t_editor));
	info->command_buf = NULL;
	info->print_buf = NULL;
	enable_rawmode(info);
	clear_screen();
	process_key_press(info);
	exitprocess(info);
}