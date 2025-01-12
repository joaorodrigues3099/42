/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:01:30 by joao-alm          #+#    #+#             */
/*   Updated: 2025/01/02 17:01:30 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "lib_print.h"

/**
 * Writes a String on the given file descriptor.
 *
 * @param s String to write.
 * @param fd File Descriptor to write on.
 */
static void	ft_putstr_fd(char *s)
{
	if (!s)
		return ;
	while (*s)
		write(2, s++, 1);
}

int	ft_print_error(const int err_code)
{
	if (err_code == E_OK)
		return (0);
	if (err_code == E_INVALID_FORMAT)
		ft_putstr_fd(PINK "Error: "
			RESET "Format: ./client <SERVER_PID> <MESSAGE>\n");
	if (err_code == E_INVALID_PID)
		ft_putstr_fd(PINK "Error: " RESET "Invalid PID\n");
	if (err_code == E_TIMEOUT)
		ft_putstr_fd(PINK "Error: " RESET "Timeout\n");
	return (err_code);
}
