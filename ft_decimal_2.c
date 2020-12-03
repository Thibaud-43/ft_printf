/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 10:17:06 by trouchon          #+#    #+#             */
/*   Updated: 2020/12/03 10:32:27 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_decimal_zeros(t_datas *datas, int *k)
{
	while ((*k) < datas->width)
	{
		write(1, " ", 1);
		(*k)++;
	}	
}
