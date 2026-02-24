/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiasecz <mpiasecz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:51:59 by mpiasecz          #+#    #+#             */
/*   Updated: 2025/05/22 11:28:54 by mpiasecz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putstr(char *s)
{
	int	i;
	int	result;
	int	count;

	count = 0;
	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i] != '\0')
	{
		result = write(1, &s[i], 1);
		if (result < 0)
			return (-1);
		count += result;
		i++;
	}
	return (count);
}
