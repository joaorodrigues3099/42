/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:30:00 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/21 19:30:05 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_string.h"

/**
 * Copies up to size - 1 bytes from src to dest,
 * ensuring dest is null-terminated.
 *
 * @param dest String to copy to.
 * @param src String to copy from.
 * @param size Number of bytes to copy.
 * @return Returns strlen(src).
 */
char	*ft_strcpy(char *dest, const char *src)
{
	char	*start;

	start = dest;
	while (*src != '\0')
		*dest++ = *src++;
	*dest = '\0';
	return (start);
}
