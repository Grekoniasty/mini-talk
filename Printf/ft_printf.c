/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiasecz <mpiasecz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:51:53 by mpiasecz          #+#    #+#             */
/*   Updated: 2025/05/22 12:12:18 by mpiasecz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *string, ...)
{
	va_list	argums;
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!string)
		return (-1);
	va_start(argums, string);
	count = ft_helper(string, argums, i);
	va_end(argums);
	return (count);
}
