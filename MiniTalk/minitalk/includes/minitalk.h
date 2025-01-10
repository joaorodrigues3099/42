/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 07:46:49 by joao-alm          #+#    #+#             */
/*   Updated: 2024/12/31 07:46:49 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>

// COLORS
# define YELLOW "\033[38;2;255;248;147m"
# define PINK "\033[38;2;231;133;190m"
# define GREEN "\033[38;2;129;223;164m"
# define BOLD "\033[1m"
# define RESET "\033[0m"
# define COLOR_CHANGE_INTERVAL 100

// TIMEOUT
# define TIMEOUT_LIMIT 1000000
# define TIMEOUT_STEP 100000

// BIT DATA
typedef struct s_bit_data
{
	int	current_byte;
	int	bit_index;
	int	char_count;
	int	client_pid;
}		t_bit_data;

// CLIENT_DATA
typedef struct s_client_data
{
	volatile sig_atomic_t	acknowledged;
	size_t					message_len;

}		t_client_data;

#endif // MINITALK_H
