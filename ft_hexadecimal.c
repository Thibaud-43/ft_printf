/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 13:26:23 by trouchon          #+#    #+#             */
/*   Updated: 2020/12/07 14:15:19 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_hexadecimal(t_datas *datas, int majuscule)
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
		datas->decimal = ft_itoa_hexadecimal((unsigned int)nb, "0123456789ABCDEF");
	else
		datas->decimal = ft_itoa_hexadecimal((unsigned int)nb, "0123456789abcdef");
	while(datas->decimal[k])
		k++;
	if (datas->left_aligned)
	{
		tmp = k;
		while (k < datas->precision_len)
		{
			write(1, "0", 1);
			k++;
		}
		write(1, datas->decimal, tmp);
		while (z < (datas->width - k))
		{
			write(1, " ", 1);
			z++;
		}
	}
	if (!datas->left_aligned)
	{
		if (k > datas->precision_len)
			tmp = k;
		else
			tmp = datas->precision_len;
		while (z < (datas->width - tmp))
		{
			write(1, " ", 1);
			z++;	
		}
		tmp = k;
		while (k < datas->precision_len)
		{
			write(1, "0", 1);
			k++;
		}

		write(1, datas->decimal, tmp);
	}
	datas->chainelen += k + z;
}
