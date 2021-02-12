# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: helvi <helvi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 12:00:35 by hlaineka          #+#    #+#              #
#    Updated: 2021/02/12 15:22:06 by helvi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = minishell

_SRC = 	minishell.c \
		cursor_move.c \
		rawmode.c \
		screen_printing.c \
		text_editing.c \
		lexer.c \
		arrows.c \
		command_list.c \
		scanner.c \
		env.c \
		setenv.c \
		unsetenv.c \
		cd.c \
		command_execute.c \
		echo.c \
		pwd.c \
		errors.c \
		exit.c

_OBJ = $(_SRC:.c=.o)
_INC = minishell.h
_LIBFT = libft.a

SRC_DIR = src
OBJ_DIR = objs
INC_DIR = includes
LIBFT_DIR = libft

SRC = $(patsubst %,$(SRC_DIR)/%,$(_SRC))
OBJ = $(patsubst %,$(OBJ_DIR)/%,$(_OBJ))
INC = $(patsubst %,$(INC_DIR)/%,$(_INC))
LIBFT = $(patsubst %,$(LIBFT_DIR)/%,$(_LIBFT))

INC_LIBFT = -I libft/includes

FLAGS = -Wall -Wextra -Werror -I $(INC_DIR) $(INC_LIBFT)
DEBUG_FLAGS = -Wall -Wextra -Werror -g -I $(INC_DIR) $(INC_LIBFT)

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ)
	@echo make started
	@make -C $(LIBFT_DIR)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC)
	@echo obj_dir/ $@
	@$(CC) $(FLAGS) -c -o $@ $<

$(OBJ_DIR):
	@echo obj dir
	@mkdir -p $(OBJ_DIR)

debug: fclean
	@make -C $(LIBFT_DIR) debug
	$(CC) $(DEBUG_FLAGS) -o $(NAME) $(OBJ) $(LIBFT)

lib:
	@make -C $(LIBFT_DIR)

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@find . -type f -name '.DS_Store' -delete
	@find . -type f -name '*~' -print -delete -o -name "#*#" -print -delete

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@rm -rf $(OBJ_DIR)

re: fclean all
