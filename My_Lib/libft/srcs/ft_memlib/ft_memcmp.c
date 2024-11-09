/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:20:56 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/23 11:22:05 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memlib.h"

/**
 * Compares the first n bytes of area of memory pointed by s1
 * with area of memory pointed by s2.
 *
 * @param s1 Pointer to area of memory to compare with s2.
 * @param s2 Pointer to area of memory to compare with s1.
 * @param n Number of bytes to compare.
 * @return Returns 0 if s1 and s2 are equal.\n
 * Returns a negative value (the difference between the ASCII decimal values)
 * if s1 is less than 2.\n
 * Returns a positive value (the difference between the ASCII decimal values)
 * if s1 is greater than s2.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s_char1;
	unsigned char	*s_char2;
	size_t			i;

	if (n == 0)
		return (0);
	i = 0;
	s_char1 = (unsigned char *)s1;
	s_char2 = (unsigned char *)s2;
	while (i < n - 1 && s_char1[i] == s_char2[i])
	{
		i++;
	}
	return (s_char1[i] - s_char2[i]);
}
