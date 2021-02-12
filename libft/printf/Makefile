# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: helvi <helvi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/16 12:22:46 by hlaineka          #+#    #+#              #
#    Updated: 2021/02/12 17:19:04 by helvi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libftprintf.a

_SRC = ft_printf.c print_s.c print_c.c print_p.c print_x.c print_d.c print_u.c print_o.c \
print_f.c set_command_values.c va_arg_reader_functions.c helper_functions.c \
float_trim_and_round.c

_OBJ = $(_SRC:.c=.o)
_INC = printf.h

SRC_DIR = .
OBJ_DIR = ../objs
INC_DIR = ../includes

SRC = $(patsubst %,$(SRC_DIR)/%,$(_SRC))
OBJ = $(patsubst %,$(OBJ_DIR)/%,$(_OBJ))
INC = $(patsubst %,$(INC_DIR)/%,$(_INC))

INC_LIBFT = -I ../includes

FLAGS = -Wall -Wextra -Werror -I $(INC_DIR) $(INC_LIBFT)
DEBUG_FLAGS = -Wall -Wextra -Werror -g -I $(INC_DIR) $(INC_LIBFT)

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ)
	@echo printf objects done

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC)
	@echo obj_dir/ $@
	@$(CC) $(DEBUG_FLAGS) -c -o $@ $<

$(OBJ_DIR):
	@echo obj dir
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -f $(OSRC)

fclean: clean
	@rm -f $(NAME)

mclean: fclean

re: fclean all
