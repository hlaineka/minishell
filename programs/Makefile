# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 12:00:35 by hlaineka          #+#    #+#              #
#    Updated: 2020/10/30 14:45:55 by hlaineka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OSRC = $(SRC:.c=.o)

INC_MS = ../includes/minishell.h

LIB_FT = ../libft/libft.a

all: $(NAME)

$(NAME): fclean
	@cd ft_ls_src && make
	@make clean

debug: fclean
	@cd ft_ls_src && make debug
	@make clean

lib: fclean
	@cd libft && make
	@make clean

clean:
	@rm -f $(OSRC)
	@cd ft_ls_src && make clean

fclean: clean
	@rm -f env
	@rm -f setenv
	@cd ft_ls_src && make fclean

re: fclean all
