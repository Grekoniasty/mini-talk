/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiasecz <mpiasecz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:51:40 by mpiasecz          #+#    #+#             */
/*   Updated: 2025/05/22 11:00:38 by mpiasecz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_helper(const char *string, va_list argums, int i)
{
	int	retur;
	int	count;

	count = 0;
	retur = 0;
	while (string[i] != '\0')
	{
		if (string[i] != '%')
		{
			retur = write(1, &string[i], 1);
			if (retur < 0)
				return (-1);
			count += retur;
			i++;
		}
		else if (string[i] == '%')
		{
			retur = ft_str_filler(argums, (char *)string, ++i);
			if (retur < 0)
				return (-1);
			count += retur;
			i++;
		}
	}
	return (count);
}
