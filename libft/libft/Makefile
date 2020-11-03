# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 12:00:35 by hlaineka          #+#    #+#              #
#    Updated: 2020/11/02 11:30:14 by hlaineka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a


SRC = ft_itoa.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcpy.c ft_strdup.c \
ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
ft_memcmp.c ft_strncpy.c ft_strcat.c ft_memchr.c ft_strncat.c ft_strlcat.c \
ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c \
ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_is_whitespace.c \
ft_define_length.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
ft_strsplit.c ft_addstr.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
ft_lstiter.c ft_lstmap.c ft_strpaste.c ft_strset.c ft_itoa_base.c get_next_line.c \
ft_itoa_uint.c ft_str_realloc.c ft_dynamic_string.c ft_strpaste_end.c\
ft_strjoin_frees2.c ft_strpaste_digits.c ft_char_str_join.c ft_strsub_freestr.c \
ft_itoa_hexa.c ft_itoa_float.c ft_str_char_join.c ft_lstsrc.c ft_lstnewtoend.c \
ft_lstend.c ft_lstaddafter.c ft_lst_merge_sort.c ft_lst_split.c ft_lst_length.c \
ft_lst_sorted_merge.c ft_strlast.c ft_lst_reverse.c ft_strjoin_frees1.c ft_lstaddtoend.c \
print_error_and_exit.c print_error.c ft_strjoin3.c ft_strnchr.c ft_iscntrl.c \
ft_getenv.c ft_str_find_c.c ft_str_toupper.c
 
OSRC = $(SRC:.c=.o)

INC_LIBFT = ../includes/libft.h

all: $(NAME)

$(NAME): fclean
	@gcc -c -Wall -Wextra -Werror -I$(INC_LIBFT) $(SRC)

clean:
	@rm -f $(OSRC)
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

mclean: fclean

re: fclean all
