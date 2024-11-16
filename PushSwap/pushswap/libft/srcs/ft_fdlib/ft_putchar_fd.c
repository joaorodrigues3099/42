/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:29:07 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/26 15:29:18 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdlib.h"
#include <unistd.h>

/**
 * Writes a char in the given file descriptor.
 *
 * @param c Char to write.
 * @param fd File descriptor to write in.
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
