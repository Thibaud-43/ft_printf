/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:53:03 by trouchon          #+#    #+#             */
/*   Updated: 2020/12/07 11:52:41 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void				ft_pointers_2(t_datas *datas, int *k, int *z)
{
	while (datas->pointers[*k])
		(*k)++;
	if (datas->precision && *k > datas->precision_len)
		datas->precision_len = *k;
	if (datas->zero_activated)
		write(1, "0x", 2);
	if (datas->left_aligned)
	{
		if (!datas->zero_activated)
			write(1, "0x", 2);
		while (datas->precision && *z < datas->precision_len - *k)
		{
			write(1, "0", 1);
			(*z)++;
		}
		write(1, datas->pointers, *k);
	}
}

static void				ft_pointers_3(t_datas *datas, int *i, int *k)
{
	if (!datas->precision)
	{
		while (*i < (datas->width - *k - 2))
		{
			if (datas->zero_activated)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			(*i)++;
		}
	}
	else
	{
		while (*i < (datas->width - datas->precision_len - 2))
		{
			if (datas->zero_activated)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			(*i)++;
		}
	}
}

static void				ft_pointers_4(t_datas *datas, int *k, int *z)
{
	if (!datas->left_aligned)
	{
		if (!datas->zero_activated)
			write(1, "0x", 2);
		while (datas->precision && *z < datas->precision_len - *k)
		{
			write(1, "0", 1);
			(*z)++;
		}
		write(1, datas->pointers, *k);
	}
}

void					ft_pointers(t_datas *datas)
{
	int				i;
	int				k;
	int				z;
	unsigned long	nb;

	k = 0;
	i = 0;
	z = 0;
	datas->chainelen--;
	nb = va_arg(datas->ap, unsigned long);
	if (nb == 0 && datas->precision_len <= 3)
	{
		ft_zeros(datas, k, i, z);
		return ;
	}
	datas->pointers = ft_itoa_unsigned_hexadecimal(nb, "0123456789abcdef");
	ft_pointers_2(datas, &k, &z);
	ft_pointers_3(datas, &i, &k);
	ft_pointers_4(datas, &k, &z);
	datas->chainelen += i + k + z + 2;
	free(datas->pointers);
}
