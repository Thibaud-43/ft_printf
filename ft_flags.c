/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:29:02 by trouchon          #+#    #+#             */
/*   Updated: 2020/12/07 16:22:11 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_set_width_2(t_datas *datas, int tmp)
{
	if (datas->chaine[datas->cursor++] == '*')
	{
		tmp = va_arg(datas->ap, int);
		if (datas->precision)
		{
			datas->precision_star = 1;
			if (tmp < 0)
			{
				datas->left_aligned = 1;
				datas->precision = 0;
			}
			else
				datas->precision_len = tmp;
		}
		else
		{
			if (tmp < 0)
			{
				datas->left_aligned = 1;
				datas->width = tmp * (-1);
			}
			else
				datas->width = tmp;
		}
	}
}

static void		ft_set_width(t_datas *datas)
{
	int tmp;

	tmp = 0;
	while (ft_isdigit(datas->chaine[datas->cursor++]) == 1)
	{
		datas->width = datas->width * 10 +
		(datas->chaine[datas->cursor++] - 48);
		datas->cursor++;
		datas->chainelen--;
	}
	ft_set_width_2(datas, tmp);
	datas->cursor++;
	datas->chainelen--;
}

static void		ft_left_aligned(t_datas *datas)
{
	if (datas->chaine[datas->cursor++] == '-')
	{
		datas->left_aligned = 1;
		datas->cursor++;
		datas->chainelen--;
	}
}

static void		ft_precision(t_datas *datas)
{
	if (datas->chaine[datas->cursor++] == '.')
	{
		datas->chainelen--;
		datas->precision_len = 0;
		datas->precision = 1;
		datas->cursor++;
		while (ft_isdigit(datas->chaine[datas->cursor++]) == 1)
		{
			datas->precision_len = datas->precision_len * 10
			+ (datas->chaine[datas->cursor++] - 48);
			datas->cursor++;
			datas->chainelen--;
		}
	}
}

void			ft_flags(t_datas *datas)
{
	if (datas->chaine[datas->cursor++] == '0')
	{
		datas->zero_activated = 1;
		datas->chainelen--;
		datas->cursor++;
	}
	while (ft_isdigit(datas->chaine[datas->cursor++]) ||
	datas->chaine[datas->cursor++] == '-' ||
	datas->chaine[datas->cursor++] == '.' ||
	datas->chaine[datas->cursor++] == '*' ||
	datas->chaine[datas->cursor++] == ' ')
	{
		if (datas->chaine[datas->cursor++] == 0)
			return ;
		if (datas->chaine[datas->cursor++] == ' ')
		{
			write(1, " ", 1);
			datas->cursor++;
		}
		ft_set_width(datas);
		ft_left_aligned(datas);
		ft_precision(datas);
	}
}
