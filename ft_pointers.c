/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:53:03 by trouchon          #+#    #+#             */
/*   Updated: 2020/12/07 10:53:47 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_zeros(t_datas *datas, int i, int k, int z)
{
	k = 2;
	if (datas->left_aligned)
	{
		write(1, "0x", 3);
		while (datas->precision && z < datas->precision_len - k)
		{
			write(1, "0", 1);
			z++;
		}
	}
	while (i < (datas->width - 3))
	{
		if (datas->zero_activated)
			write(1, "0", 1);
		else 
			write(1, " ", 1);
		i++;
	}
	if (!datas->left_aligned)
	{
		write(1, "0x", 3);
		while (datas->precision && z < datas->precision_len - k)
		{
			write(1, "0", 1);
			z++;
		}
	}
	datas->chainelen += i + k + z ;
}

void		ft_pointers(t_datas *datas)
{
	int i;
	int k;
	int z;
	unsigned long nb;
	
	k = 0;
	i = 0;
	z = 0;
	datas->chainelen--;
	nb = va_arg(datas->ap, unsigned long);
	if (nb == 0)
	{
		ft_zeros(datas, k, i, z);
		return ;
	}
	datas->pointers = ft_itoa_unsigned_hexadecimal(nb, "0123456789abcdef");
	while (datas->pointers[k])
		k++;
	if (datas->zero_activated)
		write(1, "0x", 2);
	if (datas->left_aligned)
	{			
		if (!datas->zero_activated)
			write(1, "0x", 2);
		while (datas->precision && z < datas->precision_len - k)
		{
			write(1, "0", 1);
			z++;
		}
		write(1, datas->pointers, k);
	}
	if (!datas->precision)
	{
		while (i < (datas->width - datas->precision_len - k - 2))
		{
			if (datas->zero_activated)
				write(1, "0", 1);
			else 
				write(1, " ", 1);
			i++;
		}
	}
	else
	{
		while (i < (datas->width - datas->precision_len - 2))
		{
			if (datas->zero_activated)
				write(1, "0", 1);
			else 
				write(1, " ", 1);
			i++;
		}
	}

	if (!datas->left_aligned)
	{
		if (!datas->zero_activated)
			write(1, "0x", 2);
		while (datas->precision && z < datas->precision_len - k)
		{
			write(1, "0", 1);
			z++;
		}
		write(1, datas->pointers, k);
	}
	datas->chainelen += i + k + z + 2;
	free(datas->pointers);
}

void		ft_pourcent(t_datas *datas)
{
	int i;

	i = 0;
	NEXT();
	datas->chainelen--;
	if (datas->left_aligned)
		write(1, "%", 1);
	while (i < datas->width - 1)	
	{
		if (datas->zero_activated)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		i++;
	}
	if (!datas->left_aligned)
		write(1, "%", 1);

	datas->chainelen += i + 1;
}
