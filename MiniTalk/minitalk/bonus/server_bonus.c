/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:03:32 by joao-alm          #+#    #+#             */
/*   Updated: 2024/12/30 18:03:32 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_print.h"
#include "minitalk.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

#include "lib_char.h"

t_bit_data	g_bit_data;

/**
 * Print a character in colors, cycling every `COLOR_CHANGE_INTERVAL`.
 * Printable characters use color; others are printed normally.
 * @param colors Array of color strings for printing.
 */
void	ft_print_bit(char **colors)
{
	int	color_index;
	int	color_count;

	color_count = 0;
	while (colors[color_count])
		color_count++;
	if (ft_isprint(g_bit_data.current_byte))
	{
		color_index = (g_bit_data.char_count / COLOR_CHANGE_INTERVAL)
			% color_count;
		ft_printf("%s%c" RESET, colors[color_index], g_bit_data.current_byte);
	}
	else
		ft_printf("%c", g_bit_data.current_byte);
}

/**
 * Handle SIGUSR1/SIGUSR2 signals to reconstruct and print a message.
 * Sends SIGUSR1 acknowledgment for each received bit or null byte.
 * @param signum Signal number (SIGUSR1 or SIGUSR2).
 * @param info Signal metadata (e.g., sender PID).
 * @param context Signal context (unused).
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
		{
			ft_print_bit((char *[]){PINK, YELLOW, GREEN, NULL});
			g_bit_data.char_count++;
		}
		g_bit_data.current_byte = 0;
		g_bit_data.bit_index = 0;
	}
	if (g_bit_data.client_pid > 0)
		kill(g_bit_data.client_pid, SIGUSR1);
}

/**
 * Initialize global bit data structure.
 */
void	ft_init_data(void)
{
	g_bit_data.current_byte = 0;
	g_bit_data.bit_index = 0;
	g_bit_data.char_count = 0;
	g_bit_data.client_pid = 0;
}

/**
 * Print the server's PID in a formatted message.
 * @param pid Server process ID.
 */
void	ft_print_pid(const int pid)
{
	ft_printf("\n───────────────────────────\n");
	ft_printf(YELLOW "Hello, here's my number ;)\n" RESET);
	ft_printf(BOLD "PID: " RESET "%d\n", pid);
	ft_printf("───────────────────────────\n\n");
}

/**
 * Server program main loop.
 * Initializes global data, sets up signal handlers, prints PID,
 * and waits for signals.
 * @return Always 0 (runs indefinitely).
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
