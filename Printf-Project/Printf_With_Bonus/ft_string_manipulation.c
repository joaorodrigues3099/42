/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_manipulation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <support@toujoustudios.net>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:14:37 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/30 13:14:37 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

/**
 * Searches for the first character occurrence in the given string.
 *
 * @param str String to look inside.
 * @param c Char to look for.
 * @return Returns the pointer to the first appearance of c in str.
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

/**
 * Copies n characters from string src to string dest.
 *
 * @param dest String to copy to.
 * @param src String to copy from.
 * @param n Number of characters to copy.
 * @return Returns dest.
 */
char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (*src && i < n)
		dest[i++] = *src++;
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}

/**
 * Trimmes the given values from the beginning and end of the string.
 *
 * @param s1 String to trim.
 * @param set Set of characters to trim.
 * @return Returns the trimmed string.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	trimmed_len;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	trimmed_len = ft_strlen(s1);
	while (*s1 && ft_strchr(set, *s1))
	{
		s1++;
		trimmed_len--;
	}
	while (trimmed_len && ft_strchr(set, s1[trimmed_len - 1]))
		trimmed_len--;
	result = (char *)malloc(trimmed_len + 1);
	if (!result)
		return (NULL);
	ft_strncpy(result, s1, trimmed_len + 1);
	return (result);
}
