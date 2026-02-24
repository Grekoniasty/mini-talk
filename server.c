/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiasecz <mpiasecz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 14:22:05 by mpiasecz          #+#    #+#             */
/*   Updated: 2025/10/09 13:55:28 by mpiasecz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static unsigned char	current_char = 0;
	static int				bit_count = 0;

	(void)context;
	current_char <<= 1;
	if (sig == SIGUSR1)
		current_char |= 1;
	bit_count++;
	kill(info->si_pid, SIGUSR1);
	if (bit_count == 8)
	{
		write(1, &current_char, 1);
		current_char = 0;
		bit_count = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	if (ac != 1)
	{
		write(2, "Extra parameters in input\n", 26);
		return (1);
	}
	sa.sa_sigaction = &handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		write(2, "Error setting up signal handlers\n", 34);
		return (1);
	}
	ft_printf("%s PID: %d\n", av[0], getpid());
	while (1)
		pause();
	return (0);
}
