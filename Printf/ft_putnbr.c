/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiasecz <mpiasecz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:51:57 by mpiasecz          #+#    #+#             */
/*   Updated: 2025/05/22 11:18:58 by mpiasecz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	handle_negative(long *num)
{
	int	retur;

	retur = write(1, "-", 1);
	if (retur < 0)
		return (-1);
	*num = -(*num);
	return (retur);
}

static int	write_final_digit(char c, int count)
{
	int	retur;

	retur = write(1, &c, 1);
	if (retur < 0)
		return (-1);
	return (count + retur);
}

int	ft_putnbr(int n)
{
	char	c;
	long	num;
	int		count;
	int		retur;

	count = 0;
	num = n;
	if (num < 0)
	{
		retur = handle_negative(&num);
		if (retur < 0)
			return (-1);
		count += retur;
	}
	if (num >= 10)
	{
		retur = ft_putnbr(num / 10);
		if (retur < 0)
			return (-1);
		count += retur;
	}
	c = num % 10 + '0';
	return (write_final_digit(c, count));
}
