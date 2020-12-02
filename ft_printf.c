/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 10:49:29 by trouchon          #+#    #+#             */
/*   Updated: 2020/12/02 11:00:07 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_initializer(t_datas *datas)
{
	datas->decimal = 0;
	datas->width = 0;
	datas->left_aligned = 0;
	datas->precision = 2000000;
}

void	ft_flags(t_datas *datas)
{
	while (STR() != 's' && STR() != 'c' &&	STR() != 'd')
	{
		while (ft_isdigit(STR()) == 1 && STR() != '0')
		{
			datas->width = datas->width * 10 + (STR() - 48);
			NEXT();
			datas->chainelen--;
		}
		if (STR() == '0')
		{
			datas->zeros_activated = 1;
			NEXT();
		}
		if (STR() == '*')
		{
			datas->width = va_arg(datas->ap, int);
			NEXT();
			datas->chainelen--;
		}
		if (STR() == '-')
		{
			datas->left_aligned = 1;
			NEXT();
			datas->chainelen--;
		}
		if (STR() == '.')
		{
			datas->chainelen--;
			NEXT();
			datas->precision = 0;
			while (ft_isdigit(STR()) == 1)
			{
				datas->precision = datas->precision * 10 + (STR() - 48);
				NEXT();
				datas->chainelen--;
			}
		}
	}
}

void	ft_parse(t_datas *datas)
{
	
	NEXT();
	datas->chainelen--;
// RESET DES PARAMS VARIABLES DE LA STRUCT //
	ft_initializer(datas);
// DETERMINATION DES FLAGS //
	ft_flags(datas);
// STRINGS //
//	printf (" width : %d", datas->width);
	if (STR() == 's' || STR() == 'c')
		ft_string(datas);
/*	if (datas->chaine[datas->cursor] == 'd')
		ft_decimal(datas);*/
}

int	ft_printf(const char *chaine, ...)
{
	t_datas	datas;
	va_start(datas.ap, chaine);

	datas.cursor = 0;
	datas.chaine = (char *)chaine;
	datas.chainelen = ft_strlen(datas.chaine);

// ECRITURE DE LA CHAINE //
	while (chaine[datas.cursor])
	{
		if (chaine[datas.cursor] == '%')
		{
			ft_parse(&datas);
		}
		else
			write(1, &chaine[datas.cursor], 1);
		datas.cursor++;
	}
	va_end(datas.ap);
	return (datas.chainelen);
}
