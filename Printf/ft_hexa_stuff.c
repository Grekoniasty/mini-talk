/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_stuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiasecz <mpiasecz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:51:43 by mpiasecz          #+#    #+#             */
/*   Updated: 2025/06/02 14:24:05 by mpiasecz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	hexa_stuff(unsigned int unum, char *string, int i)
{
	int	count;
	int	retur;

	retur = 0;
	count = 0;
	if (string[i] == 'x')
	{
		retur = ft_putnbr_base(unum, "0123456789abcdef");
		if (retur < 0)
			return (-1);
		count += retur;
	}
	else if (string[i] == 'X')
	{
		retur = ft_putnbr_base(unum, "0123456789ABCDEF");
		if (retur < 0)
			return (-1);
		count += retur;
	}
	return (count);
}
