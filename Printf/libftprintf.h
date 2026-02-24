/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiasecz <mpiasecz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:52:05 by mpiasecz          #+#    #+#             */
/*   Updated: 2025/07/29 12:47:09 by mpiasecz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_putnbr_base(unsigned long nbr, char *base);
int	ft_printchr(char *string, int i, va_list argums);
int	ft_printchrnum(char *string, int i, va_list argums);
int	ft_str_filler(va_list argums, char *string, int i);
int	ft_printf(const char *string, ...);
int	ft_putnbr_u(unsigned int n);
int	ft_pointer(va_list argums);
int	hexa_stuff(unsigned int unum, char *string, int i);
int	ft_helper(const char *string, va_list argums, int i);

#endif
