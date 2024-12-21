/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 07:56:43 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/23 07:56:47 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strlib.h"

/**
 * Compares the first n bytes of strings s1 and s2.
 *
 * @param s1 String 1.
 * @param s2 String 2.
 * @param n Number of bytes to compare.
 * @return Returns 0 if s1 and s2 are equal.\n
 * Returns a negative value (the difference between the ASCII decimal values)
 * if s1 is less than 2.\n
 * Returns a positive value (the difference between the ASCII decimal values)
 * if s1 is greater than s2.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!n)
		return (0);
	i = 0;
	while (i < n - 1 && s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
