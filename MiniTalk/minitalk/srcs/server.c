/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:09:56 by joao-alm          #+#    #+#             */
/*   Updated: 2024/12/30 15:20:23 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_print.h"
#include "minitalk.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

t_bit_data	g_bit_data;

/**
 * Process signals to reconstruct and print a message.
 * SIGUSR1 and SIGUSR2 form bits to build bytes; prints char or newline on '\0'.
 * @param signum Signal number (SIGUSR1 or SIGUSR2).
 * @param info Signal info structure (contains sender PID).
 * @param context Unused.
 */
void	signal_handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (info != NULL)
		g_bit_data.client_pid = info->si_pid;
	if (signum == SIGUSR2)
		g_bit_data.current_byte |= (1 << (7 - g_bit_data.bit_index));
	g_bit_data.bit_index++;
	if (g_bit_data.bit_index == 8)
	{
		if (g_bit_data.current_byte == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", g_bit_data.current_byte);
		g_bit_data.current_byte = 0;
		g_bit_data.bit_index = 0;
	}
	if (g_bit_data.client_pid > 0)
		kill(g_bit_data.client_pid, SIGUSR1);
}

/**
 * Initialize global data for message reconstruction.
 */
void	ft_init_data(void)
{
	g_bit_data.current_byte = 0;
	g_bit_data.bit_index = 0;
	g_bit_data.client_pid = 0;
}

/**
 * Print the server PID in a formatted message.
 * @param pid Process ID to display.
 */
void	ft_print_pid(const int pid)
{
	ft_printf("\n───────────────────────────\n");
	ft_printf(YELLOW "Hello, here's my number ;)\n" RESET);
	ft_printf(BOLD "PID: " RESET "%d\n", pid);
	ft_printf("───────────────────────────\n\n");
}

/**
 * Server main function.
 * Sets up signal handlers and prints server PID.
 * Waits indefinitely for signals to process messages.
 * @return Always 0.
 */
int	main(void)
{
	struct sigaction	signal_received;

	ft_init_data();
	ft_print_pid(getpid());
	signal_received.sa_sigaction = signal_handler;
	signal_received.sa_flags = SA_RESTART | SA_SIGINFO;
	sigemptyset(&signal_received.sa_mask);
	sigaction(SIGUSR1, &signal_received, NULL);
	sigaction(SIGUSR2, &signal_received, NULL);
	while (1)
		pause();
}
