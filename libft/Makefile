# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: helvi <helvi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 12:00:35 by hlaineka          #+#    #+#              #
#    Updated: 2021/02/12 22:03:31 by helvi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OBJS = objs/*.o

INC = includes/libft.h includes/ft_printf.h

all: $(NAME)

$(NAME):
	@cd libft && make -s
	@cd printf && make -s
	@ar rc $(NAME) $(OBJS) $(INC)

debug:
	@cd libft && make -s
	@cd printf && make -s
	@ar rc $(NAME) $(OBJS) $(INC)

clean:
	@rm -f $(OBJS)
	@echo library object files removed.

fclean:
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@echo library .a file removed. Object folder removed.

re: fclean all
