/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiasecz <mpiasecz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:51:37 by mpiasecz          #+#    #+#             */
/*   Updated: 2025/10/09 13:51:47 by mpiasecz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./Printf/libftprintf.h"
# include "./libft/libft.h"
# include <signal.h>

typedef struct s_state
{
	unsigned char	current_char;
	int				bit_count;
}					t_state;

#endif
