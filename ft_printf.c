/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 10:49:29 by trouchon          #+#    #+#             */
/*   Updated: 2020/12/02 14:08:22 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_initializer(t_datas *datas)
{
	datas->decimal = 0;
	datas->width = 0;
	datas->left_aligned = 0;
	datas->precision = 2000000;
	datas->zero_activated = 0;
}

static void		ft_parser(t_datas *datas)
{
	NEXT();
	datas->chainelen--;
	ft_initializer(datas);
	ft_flags(datas);
	if (STR() == 's' || STR() == 'c')
		ft_string(datas);
	if (STR() == 'd')
		ft_decimal(datas);
}

int		ft_printf(const char *chaine, ...)
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
			ft_parser(&datas);
		}
		else
			write(1, &chaine[datas.cursor], 1);
		datas.cursor++;
	}
	va_end(datas.ap);
	return (datas.chainelen);
}
