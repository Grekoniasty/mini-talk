/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchrnum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiasecz <mpiasecz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:51:51 by mpiasecz          #+#    #+#             */
/*   Updated: 2025/05/27 10:38:04 by mpiasecz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_xx(char *string, int i, va_list argums, int count)
{
	unsigned int	unum;
	int				retur;

	retur = 0;
	unum = va_arg(argums, unsigned int);
	retur = hexa_stuff(unum, string, i);
	if (retur < 0)
		return (-1);
	count += retur;
	return (count);
}

int	ft_printchrnum(char *string, int i, va_list argums)
{
	int	count;
	int	retur;

	count = 0;
	retur = 0;
	if (string[i] == 'x' || string[i] == 'X')
	{
		count = ft_xx(string, i, argums, count);
	}
	else if (string[i] == 'i' || string[i] == 'd')
	{
		retur = ft_putnbr(va_arg(argums, int));
		if (retur < 0)
			return (-1);
		count += retur;
	}
	else if (string[i] == 'u')
	{
		retur = ft_putnbr_base(va_arg(argums, unsigned int), "0123456789");
		if (retur < 0)
			return (-1);
		count += retur;
	}
	return (count);
}
