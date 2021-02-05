/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <hlaineka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:58:27 by hlaineka          #+#    #+#             */
/*   Updated: 2021/02/05 13:02:01 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdint.h>
# include "ft_printf.h"
# define T_INT_MAX 2147483647
# define T_INT_MIN -2147483648
# define BUFF_SIZE 8
# define FD_LIMIT 4864
# define TRUE 1
# define FALSE 0

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;

}					t_list;

/*
** Basic functions
*/
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
size_t				ft_strlen(char const *s);
char				*ft_itoa(int n);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dest, const char *src);
void				*ft_memset(void *ptr, int value, size_t num);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t num);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t num);
int					ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
char				*ft_strncpy(char *dest, const char *src, size_t num);
char				*ft_strcat(char *dest, const char *src);
void				*ft_memchr(const void *ptr, int c, size_t num);
char				*ft_strncat(char *dest, const char *src, size_t num);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strchr(const char *src, int c);
char				*ft_strrchr(const char *src, int c);
char				*ft_strstr(const char *str1, const char *str2);
char				*ft_strnstr(const char *str1, const char *str2, size_t n);
int					ft_strcmp(const char *str1, const char *str2);
int					ft_strncmp(const char *str1, const char *str2, size_t num);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int arg);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s);
char				**ft_strsplit(const char *s, char c);

/*
** List functions
*/
t_list				*ft_lstnew(const void *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new_list);
void				ft_lstiter(t_list *lst, void (*f)(t_list*elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstsrc(const void *content, t_list *beginning);
void				ft_lstnewtoend(const void *content, size_t content_size,
					t_list **beginning);
t_list				*ft_lstend(t_list *beginning);
void				ft_lstaddafter(t_list *end, t_list *newelem);
void				ft_lst_merge_sort(t_list **first, int (*f)(t_list *elem_a,
					t_list *elem_b));
void				ft_lst_split(t_list *first, t_list **a, t_list **b);
int					ft_lst_length(t_list *first);
t_list				*ft_lst_sorted_merge(t_list *a, t_list *b,
					int (*f)(t_list *elem_a, t_list *elem_b));
t_list				*ft_lst_reverse(t_list **first);
void				ft_lstaddtoend(const void *content, size_t content_size,
					t_list **beginning);

/*
** Own adds.
*/
int					get_next_line(const int fd, char **line);
char				*ft_dynamic_string(char **dest, char *src, int num);
char				**ft_addstr(char **dest, char *src);
int					ft_define_length(int n);
int					ft_is_whitespace(const char c);
char				*ft_str_realloc(char *src, int start, int end);
char				*ft_strset(char value, size_t num);
void				ft_strpaste(char *dest, char *src);
char				*ft_strjoin_frees2(char *s1, char *s2);
char				*ft_strjoin_frees1(char *s1, char *s2);
void				ft_strpaste_digits(char *dest, char *src);
char				*ft_char_str_join(char c, char *s1);
char				*ft_strsub_freestr(char *s, unsigned int start, size_t len);
void				ft_strpaste_end(char *dest, char *src);
char				*ft_str_char_join(char c, char *s1);
char				ft_strlast(char const *str);
void				print_error_and_exit(char *name);
void				print_error(char *directory_name);
char				*ft_strjoin3(char *str1, char *str2, char *str3);
char				*ft_strnchr(const char *src, int c);
int					ft_iscntrl(int c);
char				*ft_getenv(char **envp_pointer, char *name);
int					ft_str_find_c(const char *src, int c);
char*				ft_str_toupper(char *str);
char				**ft_strarr_copy(char **src);
void				ft_free(void *variable);
int					ft_array_length(char **array);
void 				ft_strarray_free(char **strarr);
char				*ft_replace_char(char *src, int i, char *input);
char				**ft_strarr_add(char **arr, char *str);
char				**ft_strarr_addfront(char **arr, char *str);
char				*ft_strsub_mid(const char *s, unsigned int start, size_t end);
int					ft_str_rfind_c(const char *src, int c);
char				*ft_str_deli(const char *str, int i);
char				*ft_str_addi(const char *str, int i, char c);

/*
** Different itoa functions to handle different data types
*/
int					ft_define_base_length(long long int n, int base);
char				*ft_itoa_base(long long int n, long long int base);
char				*ft_itoa_uint(uintmax_t n, unsigned int	base);
char				*ft_itoa_hexa(uintmax_t n);
char				*ft_itoa_float(long double n);

#endif
