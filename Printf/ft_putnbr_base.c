/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiasecz <mpiasecz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:51:54 by mpiasecz          #+#    #+#             */
/*   Updated: 2025/07/29 12:46:51 by mpiasecz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr_base(unsigned long nbr, char *base)
{
	int	count;
	int	base_len;
	int	retur;

	retur = 0;
	count = 0;
	base_len = ft_strlen(base);
	if (base_len == 0)
		return (-1);
	if (nbr / base_len > 0)
	{
		retur = ft_putnbr_base(nbr / base_len, base);
		if (retur < 0)
			return (-1);
		count += retur;
	}
	retur = write(1, &base[nbr % base_len], 1);
	if (retur < 0)
		return (-1);
	count += retur;
	return (count);
}
