/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:13:43 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/22 12:13:48 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strlib.h"

/**
 * Concatenates src to the end of dest, ensuring dest doesn't overflow
 * and is null-terminated.
 *
 * @param dest String to get concatenated by src.
 * @param src String to concatenate to the end of dest.
 * @param size Number of bytes to concatenate.
 * @return If size is smaller than strlen(dest), returns strlen(src) + size.\n
 * Else, returns strlen(dest) + strlen(src).
 */
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	space_left;

	src_len = ft_strlen(src);
	if (!dest && !size)
		return (src_len);
	dest_len = ft_strlen(dest);
	if (size <= dest_len)
		return (src_len + size);
	space_left = size - dest_len - 1;
	dest += dest_len;
	while (space_left-- > 0 && *src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest_len + src_len);
}
