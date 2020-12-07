/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 17:35:45 by trouchon          #+#    #+#             */
/*   Updated: 2020/12/07 16:49:46 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <assert.h>
# include <stdarg.h>
#include <stdio.h>

typedef struct	s_datas
{
	va_list			ap;
	int				cursor;
	char			*chaine;
	int				chainelen;
	char			*str;
	char			*decimal;
	int				width;
	int				precision;
	int				precision_len;
	int				precision_star;
	int				left_aligned;
	int				zero_activated;
	int				c;
	char			*pointers;

}				t_datas;

void			ft_hexadecimal(t_datas *datas, int majuscule);
void			ft_zeros(t_datas *datas, int i, int k, int z);
void			ft_pourcent(t_datas *datas);
char			*ft_itoa_unsigned_hexadecimal(unsigned long num, char *base);
char			*ft_itoa_hexadecimal(unsigned int num, char *base);
void			ft_pointers(t_datas *datas);
void			ft_decimal_next(t_datas *datas, int *i,
int *k, int is_negative);
void			ft_character(t_datas *datas);
void			ft_decimal4(t_datas *datas, int *i, int *k, int is_negative);
void			ft_decimal_zeros(t_datas *datas, int *k);
int				ft_decimal(t_datas *datas);
int				ft_decimal_unsigned(t_datas *datas);
void			ft_flags(t_datas *datas);
int				ft_printf(const char *chaine, ...);
void			ft_string(t_datas *datas);
char			*ft_itoa(int n);
char			*ft_itoa_unsigned(unsigned int n);
int				ft_isdigit(int i);
int				ft_strlen(char *str);

#endif
