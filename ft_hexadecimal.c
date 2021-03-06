/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 13:26:23 by trouchon          #+#    #+#             */
/*   Updated: 2020/12/07 14:41:16 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_hexadecimal2(t_datas *datas, int *k, int *z, int *tmp)
{
	if (datas->left_aligned)
	{
		*tmp = *k;
		while (*k < datas->precision_len)
		{
			write(1, "0", 1);
			(*k)++;
		}
		write(1, datas->decimal, *tmp);
		while (*z < (datas->width - *k))
		{
			if (datas->zero_activated && !datas->precision)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			(*z)++;
		}
	}
}

static void		ft_hexadecimal3(t_datas *datas, int *k, int *z, int *tmp)
{
	if (!datas->left_aligned)
	{
		if (*k > datas->precision_len)
			*tmp = *k;
		else
			*tmp = datas->precision_len;
		while (*z < (datas->width - *tmp))
		{
			if (datas->zero_activated && !datas->precision)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			(*z)++;
		}
		*tmp = *k;
		while (*k < datas->precision_len)
		{
			write(1, "0", 1);
			(*k)++;
		}
		write(1, datas->decimal, *tmp);
	}
}

void			ft_hexadecimal(t_datas *datas, int majuscule)
{
	int nb;
	int k;
	int tmp;
	int z;

	k = 0;
	tmp = 0;
	z = 0;
	nb = va_arg(datas->ap, int);
	datas->chainelen--;
	if (majuscule == 1)
		datas->decimal = ft_itoa_hexadecimal((unsigned int)nb,
		"0123456789ABCDEF");
	else
		datas->decimal = ft_itoa_hexadecimal((unsigned int)nb,
		"0123456789abcdef");
	while (datas->decimal[k])
		k++;
	if (datas->decimal[0] == '0' && datas->decimal[1] == 0 &&
		datas->precision && datas->precision_len == 0)
		k = 0;
	ft_hexadecimal2(datas, &k, &z, &tmp);
	ft_hexadecimal3(datas, &k, &z, &tmp);
	free(datas->decimal);
	datas->chainelen += k + z;
}
