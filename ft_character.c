/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_character.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:03:29 by trouchon          #+#    #+#             */
/*   Updated: 2020/12/03 14:12:24 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_character(t_datas *datas)
{
	datas->chainelen--;
	datas->c = va_arg(datas->ap, int);
	write(1, &datas->c, 1);
	datas->chainelen++;
}
