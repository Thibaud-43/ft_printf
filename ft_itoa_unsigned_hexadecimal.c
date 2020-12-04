/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned_hexadecimal.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 09:02:49 by trouchon          #+#    #+#             */
/*   Updated: 2020/12/04 11:36:18 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_size(unsigned long n)
{
	int i;

	i = 0;
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

char		*ft_itoa_unsigned_hexadecimal(unsigned long num, char *base)
{
	char				*dst;
	int					count;
	int					i;

	count = ft_count_size(num);
	i = 0;
	if (num < 0 || count == 0)
		count++;
	if (!(dst = malloc(sizeof(char) * (count + 1))))
		return (NULL);
	dst[count] = '\0';
	while (count > i)
	{
		dst[--count] = base[num % 16];
		num /= 16;
	}
	return (dst);
}
