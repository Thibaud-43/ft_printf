/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 09:30:24 by trouchon          #+#    #+#             */
/*   Updated: 2020/12/02 14:10:40 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_decimal(t_datas *datas)
{
	int i;
	
	i = 0;
	datas->chainelen--;
	datas->decimal = ft_itoa(va_arg(datas->ap, int));
	while (datas->decimal[i])
		i++;
	write(1, datas->decimal, i);
	datas->chainelen += i;
}
