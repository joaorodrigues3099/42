/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:42:11 by joao-alm          #+#    #+#             */
/*   Updated: 2024/12/30 12:42:11 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_print.h"
#include "lib_conversion.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "minitalk.h"

t_client_data	g_client_data;

/**
 * Set acknowledgment flag on SIGUSR1.
 * @param signum Signal number (SIGUSR1).
 */
void	acknowledge_signal(int signum)
{
	if (signum == SIGUSR1)
		g_client_data.acknowledged = 1;
}

/**
 * Wait for acknowledgment or exit on timeout.
 * @return 1 if acknowledged, 0 on timeout.
 */
void	wait_for_acknowledgment(void)
{
	int	elapsed_time;

	elapsed_time = 0;
	while (g_client_data.acknowledged == 0)
	{
		usleep(TIMEOUT_STEP);
		elapsed_time += TIMEOUT_STEP;
		if (elapsed_time >= TIMEOUT_LIMIT)
			exit(ft_print_error(E_TIMEOUT));
	}
}

/**
 * Send a string to the server as binary signals.
 * SIGUSR2 for 1, SIGUSR1 for 0, ends with a null terminator.
 * @param pid Server process ID.
 * @param str String to send.
 */
static void	ft_send_message(const int pid, const char *str)
{
	int		shift;
	size_t	i;

	i = -1;
	while (str[++i])
	{
		shift = 8;
		while (--shift >= 0)
		{
			g_client_data.acknowledged = 0;
			if ((str[i] >> shift) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			wait_for_acknowledgment();
		}
	}
	shift = 8;
	while (--shift >= 0)
	{
		g_client_data.acknowledged = 0;
		kill(pid, SIGUSR1);
		wait_for_acknowledgment();
	}
}

/**
 * Client main function.
 * Validates input and sends a message to the server.
 * @param ac Argument count.
 * @param av Argument array.
 * @return 0 on success, 1 on error.
 */
int	main(const int ac, char **av)
{
	int	pid;

	if (ac != 3)
		return (ft_print_error(E_INVALID_FORMAT));
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		return (ft_print_error(E_INVALID_PID));
	signal(SIGUSR1, acknowledge_signal);
	ft_send_message(pid, av[2]);
	return (E_OK);
}
