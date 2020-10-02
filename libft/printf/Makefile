# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/16 12:22:46 by hlaineka          #+#    #+#              #
#    Updated: 2020/09/03 13:33:52 by hlaineka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c print_s.c print_c.c print_p.c print_x.c print_d.c print_u.c print_o.c \
print_f.c set_command_values.c va_arg_reader_functions.c helper_functions.c \
float_trim_and_round.c

OBJ = $(SRCS:.c=.o)

INC = ft_printf.h

INC_LIBFTA = ../libft/libft.a

INC_LIBFT = ../includes/libft.h

INC_PRINTF = ../includes/ft_printf.h

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Wextra -Werror $(SRCS) $(INC_LIBFT) $(INC_PRINTF)

main: re
	@gcc main.c -o test libftprintf.a
	@make clean

main_string: re
	@gcc mainft.c -o stringft libftprintf.a
	@gcc mainpf.c -o stringpf libftprintf.a
	@make clean

main_hex: re
	@gcc main_hexft.c -o hexft libftprintf.a
	@gcc main_hexpf.c -o hexpf libftprintf.a
	@make clean

main_int: re
	@gcc main_intft.c -o intft libftprintf.a
	@gcc main_intpf.c -o intpf libftprintf.a
	@make clean

main_float: re
	@gcc main_floatft.c -o floatft libftprintf.a
	@gcc main_floatpf.c -o floatpf libftprintf.a
	@make clean
	
main_ansi: re
	@gcc main_ansi.c -o ansi libftprintf.a
	@make clean

compare:
	@gcc compare.c -o compare libftprintf.a

clean:
	@rm -rf $(OBJ)
	@rm -rf *.o 
	@rm -rf *~

fclean: clean
	@rm -rf *.o 
	@rm -rf ft_printf
	@rm -rf $(NAME)

re: fclean all
