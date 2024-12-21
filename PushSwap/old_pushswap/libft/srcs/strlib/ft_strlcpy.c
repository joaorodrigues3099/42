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

#include "../../includes/strlib.h"

/**
 * Copies up to size - 1 bytes from src to dest,
 * ensuring dest is null-terminated.
 *
 * @param dest String to copy to.
 * @param src String to copy from.
 * @param size Number of bytes to copy.
 * @return Returns strlen(src).
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	count;

	count = 0;
	while (src[count])
		count++;
	if (size)
	{
		while (--size && *src)
			*dest++ = *src++;
		*dest = 0;
	}
	return (count);
}
