# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: helvi <helvi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 12:00:35 by hlaineka          #+#    #+#              #
#    Updated: 2021/02/12 16:59:03 by helvi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OBJS = objs/*.o

INC = includes/libft.h includes/ft_printf.h

all: $(NAME)

$(NAME):
	cd libft && make
	cd printf && make
	@ar rc $(NAME) $(OBJS) $(INC)

debug:
	make libft && make
	cd printf && make

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
