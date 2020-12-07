/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 10:49:29 by trouchon          #+#    #+#             */
/*   Updated: 2020/12/07 16:52:21 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_initializer(t_datas *datas)
{
	datas->width = 0;
	datas->left_aligned = 0;
	datas->precision = 0;
	datas->precision_len = 0;
	datas->zero_activated = 0;
	datas->precision_star = 0;
}

static int		ft_parser_2(t_datas *datas)
{
	if (datas->chaine[datas->cursor] == 0)
		return (0);
	if (datas->chaine[datas->cursor] == '%')
	{
		ft_pourcent(datas);
		return (1);
	}
	if (datas->chaine[datas->cursor] == 's')
		ft_string(datas);
	if (datas->chaine[datas->cursor] == 'd'
	|| datas->chaine[datas->cursor] == 'i')
	{
		if (!(ft_decimal(datas)))
			return (0);
	}
	if (datas->chaine[datas->cursor] == 'c')
		ft_character(datas);
	return (1);
}

static int		ft_parser_1(t_datas *datas)
{
	datas->cursor++;
	datas->chainelen--;
	ft_initializer(datas);
	ft_flags(datas);
	if (!ft_parser_2(datas))
		return (0);
	if (datas->chaine[datas->cursor] == 'u')
	{
		if (!(ft_decimal_unsigned(datas)))
			return (0);
	}
	if (datas->chaine[datas->cursor] == 'p')
		ft_pointers(datas);
	if (datas->chaine[datas->cursor] == 'x')
		ft_hexadecimal(datas, 0);
	if (datas->chaine[datas->cursor] == 'X')
		ft_hexadecimal(datas, 1);
	return (1);
}

int				ft_printf(const char *chaine, ...)
{
	t_datas	datas;

	va_start(datas.ap, chaine);
	datas.cursor = 0;
	datas.chaine = (char *)chaine;
	datas.chainelen = ft_strlen(datas.chaine);
	while (chaine[datas.cursor])
	{
		if (chaine[datas.cursor] == '%')
		{
			if (!(ft_parser_1(&datas)))
				return (0);
		}
		else
			write(1, &chaine[datas.cursor], 1);
		if (chaine[datas.cursor])
			datas.cursor++;
	}
	va_end(datas.ap);
	return (datas.chainelen);
}
