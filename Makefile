# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: helvi <helvi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 12:00:35 by hlaineka          #+#    #+#              #
#    Updated: 2021/02/12 22:00:37 by helvi            ###   ########.fr        #
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
	@echo "\n"object files made."\n"
	@cd $(LIBFT_DIR) && make -s
	@echo libraries ready.
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT)
	@echo compiled!

debug: $(OBJ_DIR) $(OBJ)
	@echo "\n"object files made."\n"
	@cd $(LIBFT_DIR) && make -s debug
	@$(CC) $(DEBUG_FLAGS) -o $(NAME) $(OBJ) $(LIBFT)
	@echo minishell compiled with -g.

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC)
	@echo -n "|"
	@$(CC) $(DEBUG_FLAGS) -c -o $@ $<

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

lib:
	@cd $(LIBFT_DIR) && make -s

clean:
	@rm -f $(OBJ)
	@echo minishell object files removed.
	@cd $(LIBFT_DIR) && make -s clean
	@find . -type f -name '.DS_Store' -delete
	@find . -type f -name '*~' -print -delete -o -name "#*#" -print -delete

fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFT_DIR) && make -s fclean
	@rm -rf $(OBJ_DIR)
	@echo minishell removed. Object folder removed.
	

re: fclean all
