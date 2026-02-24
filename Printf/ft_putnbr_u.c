/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiasecz <mpiasecz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:51:55 by mpiasecz          #+#    #+#             */
/*   Updated: 2025/05/22 11:28:41 by mpiasecz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr_u(unsigned int n)
{
	char	c;
	int		count;
	int		retur;

	if (n < 10)
		count = 0;
	else
		count = ft_putnbr_u(n / 10);
	if (count < 0)
		return (-1);
	c = n % 10 + '0';
	retur = write(1, &c, 1);
	if (retur < 0)
		return (-1);
	return (count + retur);
}
