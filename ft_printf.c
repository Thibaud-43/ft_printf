/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 10:49:29 by trouchon          #+#    #+#             */
/*   Updated: 2020/12/03 14:41:35 by trouchon         ###   ########.fr       */
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

static int		ft_parser(t_datas *datas)
{
	NEXT();
	datas->chainelen--;
	ft_initializer(datas);
	ft_flags(datas);
	if (STR() == 's')
		ft_string(datas);
	if (STR() == 'd' || STR() == 'i')
	{
		if (!(ft_decimal(datas)))
			return (0);
	}
	if (STR() == 'c')
		ft_character(datas);
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
			if (!(ft_parser(&datas)))
				return (0);
		}
		else
			write(1, &chaine[datas.cursor], 1);
		datas.cursor++;
	}
	va_end(datas.ap);
	return (datas.chainelen);
}
