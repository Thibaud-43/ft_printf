/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 10:49:29 by trouchon          #+#    #+#             */
/*   Updated: 2020/12/01 14:07:20 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_initializer(t_datas *datas)
{
	datas->decimal = 0;
	datas->width = 0;
	datas->left_aligned = 0;
}

void	ft_flags(t_datas *datas)
{
	while (STR() != 's' && STR() != 'c' &&	STR() != 'd')
	{
		if (ft_isdigit(STR()) == 1)
			datas->width = datas->width * 10 + (STR() - 48);
		if (STR() == '*')
			datas->width = va_arg(datas->ap, int);
		if (STR() == '-')
			datas->left_aligned = 1;		
		datas->cursor++;
	}
	
}

void	ft_parse(t_datas *datas)
{
	
	datas->cursor++;
	ft_initializer(datas);
	ft_flags(datas);
	if (STR() == 's' || STR() == 'c')
		ft_string(datas);
/*	if (datas->chaine[datas->cursor] == 'd')
		ft_decimal(datas);*/
}

int	ft_printf(const char *chaine, ...)
{
	t_datas	datas;
	va_start(datas.ap, chaine);

	datas.cursor = 0;
	datas.chaine = (char *)chaine;
// ECRITURE DE LA CHAINE //
	while (chaine[datas.cursor])
	{
		if (chaine[datas.cursor] == '%')
		{
			ft_parse(&datas);
		}
		else
			write(1, &chaine[datas.cursor], 1);
		datas.cursor++;
	}
	va_end(datas.ap);
	return (1);
}
/*
int main(int argc, char **argv)
{
	
	(void)argc;
	ft_printf("// MON PRINTF // ceci est la chaine : %0s %s \n", argv[1], argv[2]);
	printf("// LE PRINTF //  ceci est la chaine : %*s %s \n", 10, argv[1], argv[2]);
	return 1;
}*/
