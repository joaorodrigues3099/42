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

t_bit_data	g_bit_data;

/**
 * Print the received character in different colors
 * based on the count of characters.
 * The color changes periodically based on the value of `COLOR_CHANGE_INTERVAL`.
 * If the character is within the printable ASCII range (0 to 126),
 * it is printed with color;
 * otherwise, it is printed normally.
 * @param colors Array of color strings to use for printing the character.
 */
void	ft_print_bit(char **colors)
{
	int	color_index;
	int	color_count;

	color_count = 0;
	while (colors[color_count])
		color_count++;
	if (g_bit_data.current_byte >= 0 && g_bit_data.current_byte <= 126)
	{
		color_index = (g_bit_data.char_count / COLOR_CHANGE_INTERVAL)
			% color_count;
		ft_printf("%s%c" RESET, colors[color_index], g_bit_data.current_byte);
	}
	else
		ft_printf("%c", g_bit_data.current_byte);
}

/**
 * Signal handler for receiving binary data encoded in signals.
 * It processes SIGUSR1 and SIGUSR2 to reconstruct the original message by
 * shifting the received bits into a byte. When a full byte is received,
 * it is printed.
 * If a null byte ('\0') is received,
 * it sends a confirmation signal (SIGUSR1) back.
 * @param signum The signal number (either SIGUSR1 or SIGUSR2).
 * @param info Additional information about the signal
 * (including the sender's PID).
 * @param context The context of the signal (not used in this handler).
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

void	ft_init_data(void)
{
	g_bit_data.current_byte = 0;
	g_bit_data.bit_index = 0;
	g_bit_data.char_count = 0;
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
