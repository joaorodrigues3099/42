/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:14:53 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/21 17:03:30 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memlib.h"

/**
 * Copies n bytes from memory area src to memory area dest.
 * If memory areas overlap, it only copies to the non overlapped areas.
 *
 * @param dest Pointer to destination.
 * @param src Pointer to data to be copied.
 * @param n Number of bytes to set.
 * @return Pointer to dest.
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (s < d && (s + n) > d)
	{
		while (n--)
			*(d + n) = *(s + n);
	}
	else
	{
		while (n--)
			*d++ = *s++;
	}
	return (dest);
}
