/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiasecz <mpiasecz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 14:47:33 by mpiasecz          #+#    #+#             */
/*   Updated: 2025/10/09 13:51:51 by mpiasecz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t	g_ackn = 0;

void	ackn_handler(int sig)
{
	(void)sig;
	g_ackn = 1;
}

void	send_char(pid_t pid, unsigned char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		g_ackn = 0;
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_ackn)
			usleep(10);
		i--;
	}
}

static int	pid_check(pid_t server_pid)
{
	if (server_pid <= 0)
	{
		write(2, "Invalid PID\n", 12);
		return (1);
	}
	if (kill(server_pid, 0) == -1)
	{
		write(2, "Error: Process does not exist\n", 31);
		return (1);
	}
	return (0);
}

void	send_string(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(pid, str[i]);
		i++;
	}
	send_char(pid, '\0');
}

int	main(int ac, char **av)
{
	pid_t				server_pid;
	struct sigaction	sa;
	int					check;

	if (ac != 3)
		return (write(2, "Usage: ./client <PID> <message>\n", 33));
	server_pid = ft_atoi(av[1]);
	check = pid_check(server_pid);
	if (check != 0)
		return (check);
	sa.sa_handler = ackn_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		write(2, "Error setting up signal handler\n", 33);
		return (1);
	}
	send_string(server_pid, av[2]);
	return (0);
}
