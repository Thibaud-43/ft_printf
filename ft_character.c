/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_character.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:03:29 by trouchon          #+#    #+#             */
/*   Updated: 2020/12/03 14:29:43 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_character(t_datas *datas)
{
	int i;
	
	i = 0;
	datas->chainelen--;
	datas->c = va_arg(datas->ap, int);
	if (datas->left_aligned == 1)
		write(1, &datas->c, 1);
	while (i < datas->width - 1)
	{
		write(1, " ", 1);
		i++;
	}
	if (datas->left_aligned == 0)
		write(1, &datas->c, 1);
	datas->chainelen += (i + 1);
}
