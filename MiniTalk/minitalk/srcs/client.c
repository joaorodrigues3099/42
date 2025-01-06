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
 * Acknowledge signal received and set the global flag when SIGUSR1 is received.
 * This updates the global flag to indicate acknowledgment.
 * @param signum The signal number (SIGUSR1 in this case).
 */
void	acknowledge_signal(int signum)
{
	if (signum == SIGUSR1)
		g_client_data.acknowledged = 1;
}

/**
 * Wait for acknowledgment with a timeout.
 * This prevents the program from pausing indefinitely.
 * @return 1 if acknowledgment was received, 0 if timeout occurred.
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
 * Send a string to the server by encoding each character in binary.
 * It sends SIGUSR2 for 1 and SIGUSR1 for 0, and sends a null terminator signal.
 * @param pid The process ID of the receiving server.
 * @param str The string to be sent.
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
 * Main function for the client program.
 * It checks the number of arguments and validates the input.
 * Then, it sends the given message to the server using `ft_send_str`.
 * @param ac The number of arguments passed to the program.
 * @param av The array of arguments passed to the program.
 * @return Returns 0 if successful, 1 if there are errors in the input.
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
