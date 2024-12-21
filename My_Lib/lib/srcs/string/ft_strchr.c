/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:30:56 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/22 14:31:00 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

/**
 * Locates the first character occurrence in a string
 *
 * @param str String to locate c on
 * @param c Character to locate
 * @return Returns a pointer to the first occurrence
 * of c in str,\n OR null if c is not found.\n
 * IF c is '\0' returns a pointer to the null-terminating byte.
 */
char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}
