# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 12:00:35 by hlaineka          #+#    #+#              #
#    Updated: 2020/10/29 19:02:27 by hlaineka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OSRC = $(SRC:.c=.o)

INC_MS = ../includes/minishell.h

LIB_FT = ../libft/libft.a

all: $(NAME)

$(NAME): fclean
	@cd ft_ls_src && make
	@gcc -Wall -Wextra -Werror $(LIB_FT) env_src/env.c -o env -I$(INC_MS)
	@make clean

debug:
	@cd ft_ls_src && make debug
	@gcc -Wall -Wextra -Werror $(LIB_FT) env_src/env.c -o env -I$(INC_MS) -g
	@make clean

lib: fclean
	@cd libft && make
	@make clean

clean:
	@rm -f $(OSRC)
	@cd ft_ls_src && make clean

fclean: clean
	@rm -f env
	@cd ft_ls_src && make fclean

re: fclean all
