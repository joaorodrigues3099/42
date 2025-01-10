/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:21:17 by joao-alm          #+#    #+#             */
/*   Updated: 2025/01/06 17:21:32 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_print.h"
#include "lib_conversion.h"
#include "minitalk.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

t_client_data	g_client_data;

/**
 * Set acknowledgment flag and increment message length on SIGUSR1.
 * @param signum Signal number (SIGUSR1).
 */
void	acknowledge_signal(int signum)
{
	if (signum == SIGUSR1)
	{
		g_client_data.acknowledged = 1;
		g_client_data.message_len++;
	}
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
 * Validate input, then send the message to the server.
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
	g_client_data.message_len = 0;
	signal(SIGUSR1, acknowledge_signal);
	ft_send_message(pid, av[2]);
	ft_printf(GREEN BOLD "%d" RESET GREEN " Bytes received\n" RESET,
		(g_client_data.message_len - 1) / 8);
	return (E_OK);
}
