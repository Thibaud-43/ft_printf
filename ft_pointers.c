/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:53:03 by trouchon          #+#    #+#             */
/*   Updated: 2020/12/04 15:16:20 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_pointers(t_datas *datas)
{
	int i;

	i = 0;
	NEXT();
	datas->pointers = ft_itoa_unsigned_hexadecimal(va_arg(datas->ap, unsigned long), "0123456789abcdef");
	write(1, "0x", 2);
	while (datas->pointers[i])
		i++;
	write(1, datas->pointers, i);
	datas->chainelen += i + 2;
	free(datas->pointers);
}

void		ft_pourcent(t_datas *datas)
{
	NEXT();
	datas->chainelen--;
	datas->chainelen++;
	write(1, "%", 1);
}
