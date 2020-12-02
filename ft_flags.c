/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:29:02 by trouchon          #+#    #+#             */
/*   Updated: 2020/12/02 18:33:28 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_fill_with_zeros(t_datas *datas)
{
	if (STR() == '0')
	{
		datas->zero_activated = 1;
		datas->chainelen--;
		NEXT();
	}
}

static void		ft_set_width(t_datas *datas)
{
	while (ft_isdigit(STR()) == 1)
	{
		datas->width = datas->width * 10 + (STR() - 48);
		NEXT();
		datas->chainelen--;
	}
	if (STR() == '*')
	{
		datas->width = va_arg(datas->ap, int);
		NEXT();
		datas->chainelen--;
	}
}

static void		ft_left_aligned(t_datas *datas)
{
	if (STR() == '-')
	{
		datas->left_aligned = 1;
		NEXT();
		datas->chainelen--;
	}
}

static void		ft_precision(t_datas *datas)
{
	if (STR() == '.')
	{
		datas->chainelen--;
		NEXT();
		while (ft_isdigit(STR()) == 1)
		{
			datas->precision = 1;
			datas->precision_len = datas->precision_len * 10 + (STR() - 48);
			NEXT();
			datas->chainelen--;
		}
	}
}

void			ft_flags(t_datas *datas)
{
	ft_fill_with_zeros(datas);
	while (STR() != 's' && STR() != 'c' && STR() != 'd')
	{
		ft_set_width(datas);
		ft_left_aligned(datas);
		ft_precision(datas);
	}
}