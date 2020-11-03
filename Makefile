# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 12:00:35 by hlaineka          #+#    #+#              #
#    Updated: 2020/10/30 14:49:01 by hlaineka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = src/minishell.c src/cursor_move.c src/rawmode.c src/screen_printing.c \
src/text_editing.c src/key_press_reading.c src/arrows.c src/command_list.c \
src/command_check.c src/env.c src/setenv.c

OSRC = $(SRC:.c=.o)

INC_MS = includes/minishell.h

LIB_FT = libft/libft.a

all: $(NAME)

$(NAME): fclean
	@cd programs && make
	@gcc -Wall -Wextra -Werror $(LIB_FT) $(SRC) -o $(NAME) -I$(INC_MS)
	@make clean

debug:
	@cd programs && make debug
	@gcc -Wall -Wextra -Werror $(LIB_FT) $(SRC) -o $(NAME) -I$(INC_MS) -g
	@make clean

lib: fclean
	@cd libft && make
	@make clean

clean:
	@rm -f $(OSRC)
	@cd programs && make clean

fclean: clean
	@rm -f $(NAME)
	@cd programs && make fclean

re: fclean all
