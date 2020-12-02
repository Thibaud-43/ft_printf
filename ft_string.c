/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 09:24:32 by trouchon          #+#    #+#             */
/*   Updated: 2020/12/02 11:02:20 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_init_null(char *null)
{

	null[0] = '(';
	null[1] = 'n';
	null[2] = 'u';
	null[3] = 'l';
	null[4] = 'l';
	null[5] = ')';
}

int		ft_string_null(t_datas *datas)
{
	int		i;
	int		k;
	char	null[6];
	
	ft_init_null(null);
	i = 0;
	k = 0;
	while (null[i] && datas->precision > 0)
	{
		datas->precision--;
		i++;
	}
	if (!datas->str && datas->left_aligned == 1)
		write(1, "(null)", i);
	while (k < (datas->width - i))
	{
		if (datas->zeros_activated == 1)
			write (1, "0", 1);
		else
			write(1, " ", 1);
		k++;
	}
	if (!datas->str && datas->left_aligned == 0)
		write(1, "(null)", i);
	return (i + k);
}

void	ft_string(t_datas *datas)
{
	int i;
	int k;

	i = 0;
	k = 0;

	datas->chainelen--;
	datas->str = va_arg(datas->ap, char *);
	if (datas->str == NULL)
	{
		datas->chainelen += ft_string_null(datas);
		return ;
	}
	while (datas->str[i] && datas->precision > 0)
	{
		datas->precision--;
		i++;
	}
	if (datas->left_aligned == 1)
		write(1, datas->str, i);
	while (k < (datas->width - i))
	{
		if (datas->zeros_activated == 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		k++;
	}
	if (datas->left_aligned == 0)
		write(1, datas->str, i);
	datas->chainelen += i + k;
}
