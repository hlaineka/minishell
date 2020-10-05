# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 12:00:35 by hlaineka          #+#    #+#              #
#    Updated: 2020/10/05 12:57:27 by hlaineka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = src/minishell.c

OSRC = $(SRC:.c=.o)

INC_LS = includes/minishell.h

LIB_FT = libft/libft.a

all: $(NAME)

$(NAME): fclean
	@cd programs/ft_ls && make
	@gcc -Wall -Wextra -Werror $(LIB_FT) $(SRC) -o $(NAME) -I$(INC_LS)
	@make clean

debug:
	@cd programs/ft_ls && make debug
	@gcc -Wall -Wextra -Werror $(LIB_FT) $(SRC) -o $(NAME) -I$(INC_LS) -g
	@make clean

lib: fclean
	@cd libft && make
	@make clean

clean:
	@rm -f $(OSRC)
	@cd programs/ft_ls && make clean

fclean: clean
	@rm -f $(NAME)
	@cd programs/ft_ls && make fclean

re: fclean all
