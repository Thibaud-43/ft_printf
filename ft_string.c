/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 09:24:32 by trouchon          #+#    #+#             */
/*   Updated: 2020/12/01 16:21:05 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void	ft_string(t_datas *datas)
{
	int i;

	i = 0;
	datas->str = va_arg(datas->ap, char *);
	while (datas->str[i])
		i++;
	if (datas->left_aligned == 1)
		write(1, datas->str, i);
	while (datas -> width && datas->width-- > i)
		write(1, " ", 1);
	if (datas->left_aligned == 0)
		write(1, datas->str, i);
	datas->chainelen += i - 1;
}
