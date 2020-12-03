/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 10:17:06 by trouchon          #+#    #+#             */
/*   Updated: 2020/12/03 17:11:05 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_decimal4(t_datas *datas, int *i, int *k, int is_negative)
{
	if (is_negative == 1)
		write(1, "-", 1);
	while ((*k) < (datas->precision_len - *i + is_negative))
	{
		write(1, "0", 1);
		(*k)++;
	}
	write(1, (datas->decimal + is_negative), (*i - is_negative));
}

void		ft_decimal_zeros(t_datas *datas, int *k)
{
	while ((*k) < datas->width)
	{
		write(1, " ", 1);
		(*k)++;
	}
}

int				ft_decimal_unsigned(t_datas *datas)
{
	int					i;
	int					k;
	unsigned			z;
	int					is_negative;

	k = 0;
	is_negative = 0;
	datas->chainelen--;
	z = va_arg(datas->ap, unsigned int);
	if (z == 0 && datas->precision_len == 0 && datas->precision)
	{
		ft_decimal_zeros(datas, &k);
		datas->chainelen += ((int)z) + k;
		return (1);
	}
	if (!(datas->decimal = ft_itoa_unsigned(z)))
		return (0);
	i = 0;
	ft_decimal_next(datas, &i, &k, is_negative);
	free(datas->decimal);
	datas->chainelen += i + k;
	return (1);
}

