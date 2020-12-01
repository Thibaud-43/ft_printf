/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 09:24:32 by trouchon          #+#    #+#             */
/*   Updated: 2020/12/01 16:27:56 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void	ft_string(t_datas *datas)
{
	int i;
	int k;

	i = 0;
	k = 0;
	datas->str = va_arg(datas->ap, char *);
	while (datas->str[i])
		i++;
	if (datas->left_aligned == 1)
		write(1, datas->str, i);
	while (datas -> width && datas->width-- > i)
	{
		write(1, " ", 1);
		k++;
	}
	if (datas->left_aligned == 0)
		write(1, datas->str, i);
	datas->chainelen += i + k - 1;
}
