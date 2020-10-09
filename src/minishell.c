/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 13:37:18 by hlaineka          #+#    #+#             */
/*   Updated: 2020/10/09 09:50:32 by hlaineka         ###   ########.fr       */
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

void	add_string_to_cursor(t_editor *info, char *printable)
{
	int	i;

	i = 0;
	while(printable[i])
	{
		if (printable[i] == '\n' || info->cursorcol + 1 == info->screencols)
		{
			info->cursorrow++;
			info->cursorcol = 1;
		}
		else
			info->cursorcol++;
		i++;
	}
}

void	remove_string_from_cursor(t_editor *info, char *printable)
{
	int	i;

	i = 0;
	while(printable[i])
	{
		if (printable[i] == '\n' || info->cursorcol <= 2)
		{
			info->cursorrow--;
			info->cursorcol = 1;
		}
		else
			info->cursorcol--;
		i++;
	}
}

void	add_char_to_cursor(t_editor *info, char c)
{
	if (c == '\n' || info->cursorcol + 1 == info->screencols)
	{
		info->cursorrow++;
		info->cursorcol = 2;
	}
	else
		info->cursorcol++;
}

void	cursor_to_left(t_editor *info)
{
	if (info->cursorcol > 2)
		info->cursorcol--;
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
	//write(STDOUT_FILENO, "\x1b[H", 3);
	//ft_printf("%d:%d", info->cursorrow, info->cursorcol);
	ft_printf("\x1b[%d;%dH", info->cursorrow, info->cursorcol);
}

int	check_keypress(char c, char **command, t_editor *info)
{
	char		*temp;
	int			i;

	temp = NULL;
	if (c == 127 && (ft_strlen(*command) <= 0))
		temp = ft_strnew(1);
	else if (c == 127 && (ft_strlen(*command) > 0))
	{	
		temp = ft_strsub(*command, 0, ft_strlen(*command) - 1);
		cursor_to_left(info);
		print_screen(info, temp);
	}
	else if (c == 27)
	{
		i = c * 100 + read_key_press();
		i = i * 100 + read_key_press();
		if (i == UP || i == DOWN || i == LEFT || i == RIGHT)
			return(i);
		temp = ft_strdup(*command);
		c = 0;
	}
	else if (ft_isprint(c))
	{
		temp = ft_str_char_join(c, *command);
		add_char_to_cursor(info, c);
		print_screen(info, temp);
	}
	else
		temp = ft_strdup(*command);
	free(*command);
	*command = ft_strdup(temp);
	free(temp);
	return(0);
}

void	check_window_size(t_editor *info)
{
	struct winsize	window_size;

	info->cursorrow = 1;
	info->cursorcol = 1;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &window_size);
	info->screenrows = window_size.ws_row;
	info->screencols = window_size.ws_col;
}

void	print_string(t_editor *info, char *printable)
{
	ft_lstnewtoend(printable, ft_strlen(printable), &(info->print_buf));
	ft_putstr(printable);
	add_string_to_cursor(info, printable);
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
	command = (char*)malloc(sizeof(char));
	command = NULL;
	while (!command || !ft_strequ(command, "exit"))
	{
		free(command);
		command = ft_strnew(1);
		print_string(info, "$>");
		temp_list = info->command_buf;
		while ((c = read_key_press()) != 10)
		{
			i = check_keypress(c, &command, info);
			if (i == UP)
			{
				if (command)
					remove_string_from_cursor(info, command);
				free(command);
				command = ft_strdup((char*)temp_list->content);
				add_string_to_cursor(info, command);
				print_screen(info, command);
				if (temp_list->next)
					temp_list = temp_list->next;
			}
			//if (i == DOWN)
			//{
			//	command = ft_strdup((char*)temp_list->content);
			//	print_screen(info, (char*)temp_list->content);
			//	if (temp_list->next)
			//		temp_list = temp_list->next;
			//}
			if (i == LEFT)
			{
				//ft_printf("left");
				info->cursorshift--;
				cursor_to_left(info);
				print_screen(info, command);
			}
			if (i == RIGHT)
			{
				if (info->cursorshift < 0)
					info->cursorshift++;
				add_char_to_cursor(info, 0);
				print_screen(info, command);
			}

		}
		if (command)
		{
			ft_lstnewtoend(command, ft_strlen(command), &(info->print_buf));
			temp = ft_strjoin3("\n", command, "\n");
			print_string(info, temp);
			new_command = ft_lstnew(command, ft_strlen(command));
			ft_lstadd(&(info->command_buf), new_command);
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
	info->cursorshift = 0;
	enable_rawmode(info);
	check_window_size(info);
	clear_screen();
	process_key_press(info);
	exitprocess(info);
}