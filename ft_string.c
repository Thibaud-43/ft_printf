/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 09:24:32 by trouchon          #+#    #+#             */
/*   Updated: 2020/12/02 10:26:54 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void	ft_string(t_datas *datas)
{
	int i;
	int k;

	i = 0;
	k = 0;

	datas->chainelen--;
	datas->str = va_arg(datas->ap, char *);
	if (!datas->str)
		i = 6;
	if (!datas->str && datas->left_aligned == 1)
		write(1, "(null)", 6);
	while (datas->str && datas->str[i] && datas->precision > 0)
	{
		datas->precision--;
		i++;
	}
	if (datas->str && datas->left_aligned == 1)
		write(1, datas->str, i);
	while (k < (datas->width - i))
	{
		write(1, " ", 1);
		k++;
	}
	if (!datas->str && datas->left_aligned == 0)
		write(1, "(null)", 6);
	if (datas->str && datas->left_aligned == 0)
		write(1, datas->str, i);
	datas->chainelen += i + k;
}
