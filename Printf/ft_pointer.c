/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiasecz <mpiasecz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:51:46 by mpiasecz          #+#    #+#             */
/*   Updated: 2025/06/02 14:24:02 by mpiasecz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_pointer(va_list argums)
{
	void	*pointer;
	int		count;
	int		retur;

	count = 0;
	pointer = va_arg(argums, void *);
	if (pointer == NULL)
	{
		retur = write(1, "(nil)", 5);
		if (retur < 0)
			return (-1);
		count += retur;
	}
	else
	{
		retur = write(1, "0x", 2);
		if (retur < 0)
			return (-1);
		count += retur;
		retur = ft_putnbr_base((unsigned long)pointer, "0123456789abcdef");
		if (retur < 0)
			return (-1);
		count += retur;
	}
	return (count);
}
