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
 * Signal handler to receive binary data encoded in signals.
 * This function processes signals SIGUSR1 and SIGUSR2 to reconstruct
 * the original message by shifting the received bits into a byte.
 * Once 8 bits (1 byte) are received, it prints the corresponding character.
 * If the byte is null ('\0'),
 * it prints a newline to mark the end of the string.
 * @param signum The signal number (either SIGUSR1 or SIGUSR2).
 * @param info The siginfo_t structure containing signal details.
 * @param context Unused in this implementation.
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

void	ft_init_data(void)
{
	g_bit_data.current_byte = 0;
	g_bit_data.bit_index = 0;
	g_bit_data.client_pid = 0;
}

void	ft_print_pid(const int pid)
{
	ft_printf("\n───────────────────────────\n");
	ft_printf(YELLOW "Hello, here's my number ;)\n" RESET);
	ft_printf(BOLD "PID: " RESET "%d\n", pid);
	ft_printf("───────────────────────────\n\n");
}

/**
 * Main function for the server program.
 * It initializes the global bit data structure and sets up the signal handlers
 * for SIGUSR1 and SIGUSR2 to receive the message.
 * It also prints the server's PID.
 * The program then enters an infinite loop to wait for signals using `pause()`.
 * @return Always returns 0 (the program runs indefinitely).
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
