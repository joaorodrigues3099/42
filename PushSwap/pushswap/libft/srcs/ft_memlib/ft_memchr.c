/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:06:26 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/23 08:06:33 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memlib.h"

/**
 * Searches the first n bytes of memory for the first occurrence of c.
 *
 * @param s Pointer to memory area to search
 * @param c Character to search
 * @param n Number of bytes to search
 * @return Returns pointer to first occurrence of c.\n
 * Or NULL if c is not found.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
	{
		if (*((unsigned char *)s) == (unsigned char)c)
			return ((void *)s);
		s++;
	}
	return (NULL);
}
