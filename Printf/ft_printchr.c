/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiasecz <mpiasecz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:51:47 by mpiasecz          #+#    #+#             */
/*   Updated: 2025/06/02 14:24:10 by mpiasecz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_sp(char c, va_list argums)
{
	char	*str;
	int		retur;

	retur = 0;
	if (c == 's')
	{
		str = va_arg(argums, char *);
		retur = ft_putstr(str);
		if (retur < 0)
			return (-1);
	}
	else if (c == 'p')
	{
		retur = ft_pointer(argums);
		if (retur < 0)
			return (-1);
	}
	return (retur);
}

int	ft_printchr(char *string, int i, va_list argums)
{
	int		count;
	char	letter;
	int		retur;

	retur = 0;
	count = 0;
	if (string[i] == 's' || string[i] == 'p')
	{
		retur = ft_sp(string[i], argums);
		if (retur < 0)
			return (-1);
		count += retur;
	}
	else if (string[i] == 'c')
	{
		letter = va_arg(argums, int);
		retur = write(1, &letter, 1);
		if (retur < 0)
			return (-1);
		count += retur;
	}
	return (count);
}
