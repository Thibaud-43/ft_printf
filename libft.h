/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 17:35:45 by trouchon          #+#    #+#             */
/*   Updated: 2020/12/03 17:11:58 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
#include <assert.h>
#include <stdarg.h>
# define STR() datas->chaine[datas->cursor]
# define STR2() datas->chaine[datas->cursor++]
# define NEXT() datas->cursor++

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct  s_datas
{
	va_list	ap;
	int		cursor;
	char	*chaine;
	int		chainelen;	
	char	*str;
	char	*decimal;
	int		width;
	int		precision;
	int		precision_len;
	int		precision_star;
	int		left_aligned;
	int		zero_activated;
	int		c;

}				t_datas;

void			ft_decimal_next(t_datas *datas, int *i, int *k, int is_negative);
void			ft_character(t_datas *datas);
void			ft_decimal4(t_datas *datas, int *i, int *k, int is_negative);
void			ft_decimal_zeros(t_datas *datas, int *k);
int				ft_decimal(t_datas *datas);
int				ft_decimal_unsigned(t_datas *datas);
void			ft_flags(t_datas *datas);
int				ft_printf(const char *chaine, ...);
void			ft_string(t_datas *datas);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstadd_back(t_list **alst, t_list *new);
t_list			*ft_lstlast(t_list *lst);
int				ft_lstsize(t_list *lst);
void			ft_lstadd_front(t_list **alst, t_list *new);
t_list			*ft_lstnew(void *content);
void			ft_putnbr_fd(int n, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_itoa(int n);
char			*ft_itoa_unsigned(unsigned int n);
char			**ft_split(char const *s, char c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strjoin(char const *s1, char const *s2);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_strdup(const char *s);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strstr(const char *big, const char	*little);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
int				ft_atoi(const char *str);
int				ft_isalnum(int i);
int				ft_isalpha(int i);
int				ft_isascii(int c);
int				ft_isdigit(int i);
int				ft_isprint(int c);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
int				ft_strlen(char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strrchr(const char *s, int c);
int				ft_tolower(int i);
int				ft_toupper(int i);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset (void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
char			*ft_substr(char const *s, unsigned int start, size_t len);

#endif
