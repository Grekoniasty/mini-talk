/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfiller.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiasecz <mpiasecz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:52:00 by mpiasecz          #+#    #+#             */
/*   Updated: 2025/05/27 10:38:35 by mpiasecz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_str_filler(va_list argums, char *string, int i)
{
	int	result;

	result = 0;
	if (string[i] == '%')
		result = write(1, "%", 1);
	else if (string[i] == 'u' || string[i] == 'i'
		|| string[i] == 'x' || string[i] == 'X' || string[i] == 'd')
		result = ft_printchrnum(string, i, argums);
	else if (string[i] == 's' || string[i] == 'p' || string[i] == 'c')
		result = ft_printchr(string, i, argums);
	else
		return (-1);
	if (result < 0)
		return (-1);
	return (result);
}
