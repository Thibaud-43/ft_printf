/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 10:17:06 by trouchon          #+#    #+#             */
/*   Updated: 2020/12/03 12:13:11 by trouchon         ###   ########.fr       */
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
