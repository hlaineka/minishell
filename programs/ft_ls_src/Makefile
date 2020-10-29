# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 12:00:35 by hlaineka          #+#    #+#              #
#    Updated: 2020/10/29 18:42:01 by hlaineka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = ft_ls.c ls_print.c ls_sort.c ls_helpers.c ls_dirlist.c ls_print_helpers.c \
ls_dirlist2.c ls_dirlist3.c ls_helpers2.c

OSRC = $(SRC:.c=.o)

INC_LS = includes/ft_ls.h

LIB_FT = ../../libft/libft.a

all: $(NAME)

$(NAME): fclean
	@gcc -Wall -Wextra -Werror $(LIB_FT) $(SRC) -o $(NAME) -I$(INC_LS)
	@mv $(NAME) ../
	@make clean

debug:
	@cd ../../libft && make
	@gcc -Wall -Wextra -Werror $(LIB_FT) $(SRC) -o $(NAME) -I$(INC_LS) -g
	@mv $(NAME) ../
	@make clean

lib: fclean
	@cd ../../libft && make
	@make clean

clean:
	@rm -f $(OSRC)
	@cd ../../libft && make clean

fclean: clean
	@rm -f ../$(NAME)
	@cd ../../libft && make fclean

re: fclean all
