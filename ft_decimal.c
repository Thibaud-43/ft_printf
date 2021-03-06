/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 09:30:24 by trouchon          #+#    #+#             */
/*   Updated: 2020/12/03 17:25:13 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		decimal2_left(t_datas *datas, int *i, int *k, int is_negative)
{
	int z;

	z = 0;
	if (is_negative == 1)
		write(1, "-", 1);
	while ((z) < (datas->precision_len - *i + is_negative))
	{
		write(1, "0", 1);
		(*k)++;
		z++;
	}
	write(1, (datas->decimal + is_negative), (*i - is_negative));
	z = 0;
	while ((z) < (datas->width - datas->precision_len - is_negative))
	{
		write(1, " ", 1);
		(*k)++;
		z++;
	}
}

static void		ft_decimal2(t_datas *datas, int *i, int *k, int is_negative)
{
	int z;

	z = 0;
	if (datas->left_aligned == 1)
	{
		decimal2_left(datas, i, k, is_negative);
		return ;
	}
	while ((*k) < (datas->width - datas->precision_len - is_negative))
	{
		write(1, " ", 1);
		(*k)++;
	}
	if (datas->left_aligned == 0)
	{
		if (is_negative == 1)
			write(1, "-", 1);
		while ((z) < (datas->precision_len - *i + is_negative))
		{
			write(1, "0", 1);
			(*k)++;
			z++;
		}
		write(1, (datas->decimal + is_negative), (*i - is_negative));
	}
}

static void		ft_decimal3(t_datas *datas, int *i, int *k, int is_negative)
{
	if (is_negative && datas->zero_activated == 1 && datas->precision == 0)
		write(1, "-", 1);
	else
		is_negative = 0;
	if (datas->left_aligned == 1)
		write(1, (datas->decimal + is_negative), (*i - is_negative));
	while ((*k) < (datas->width - *i))
	{
		if (datas->zero_activated &&
			datas->left_aligned == 0 && datas->precision == 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		(*k)++;
	}
	if (datas->left_aligned == 0)
		write(1, (datas->decimal + is_negative), (*i - is_negative));
}

void			ft_decimal_next(t_datas *datas, int *i, int *k, int is_negative)
{
	if (datas->decimal[0] == '-')
		is_negative = 1;
	while (datas->decimal[*i])
		(*i)++;
	if (datas->precision == 0 && datas->width == 0)
		write(1, datas->decimal, *i);
	else if (datas->precision == 1 && datas->width &&
			(*i) < datas->precision_len)
		ft_decimal2(datas, i, k, is_negative);
	else if ((datas->precision == 0 || datas->precision_len <= *i)
			&& datas->width)
		ft_decimal3(datas, i, k, is_negative);
	else if (datas->precision == 1 && datas->width == 0)
		ft_decimal4(datas, i, k, is_negative);
}

int				ft_decimal(t_datas *datas)
{
	int i;
	int k;
	int is_negative;

	k = 0;
	is_negative = 0;
	datas->chainelen--;
	i = va_arg(datas->ap, int);
	if (i == 0 && datas->precision_len == 0 && datas->precision)
	{
		ft_decimal_zeros(datas, &k);
		datas->chainelen += i + k;
		return (1);
	}
	if (!(datas->decimal = ft_itoa(i)))
		return (0);
	i = 0;
	ft_decimal_next(datas, &i, &k, is_negative);
	free(datas->decimal);
	datas->chainelen += i + k;
	return (1);
}
