/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointers2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 11:47:56 by trouchon          #+#    #+#             */
/*   Updated: 2020/12/07 14:54:37 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_pourcent(t_datas *datas)
{
	int i;

	i = 0;
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

static void		ft_zeros_2(t_datas *datas, int *i, int *k, int *z)
{
	while (*i < (datas->width - *k))
	{
		if (datas->zero_activated)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		(*i)++;
	}
	if (!datas->left_aligned)
	{
		write(1, "0x0", *k);
		while (datas->precision && *z < datas->precision_len - *k)
		{
			write(1, "0", 1);
			(*z)++;
		}
	}
}

void			ft_zeros(t_datas *datas, int i, int k, int z)
{
	k = 3;
	if (datas->precision && datas->precision < 3 && datas->precision_star == 0)
		k = 2;
	if (datas->left_aligned)
	{
		write(1, "0x0", k);
		while (datas->precision && z < datas->precision_len - k)
		{
			write(1, "0", 1);
			z++;
		}
	}
	ft_zeros_2(datas, &i, &k, &z);
	datas->chainelen += i + k + z;
}
