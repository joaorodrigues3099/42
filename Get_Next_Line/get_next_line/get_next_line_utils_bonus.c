/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <support@toujoustudios.net>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:17:41 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/08 16:17:41 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/**
 * Finds the first occurrence of a character in a string.
 *
 * @param str String to search
 * @param c Character to find
 * @return Pointer to the first occurrence of c, or NULL if not found
 * IF c is '\0', returns a pointer to the null terminator.
 */
char	*ft_strchr(const char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}

/**
 * Returns the length of the string.
 *
 * @param s String to measure
 * @return Length of the string
 */
size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

/**
 * Fills the first 'n' bytes of memory with the given character.
 *
 * @param s Pointer to memory
 * @param c Character to set
 * @param n Number of bytes to set
 * @return Pointer to the memory area
 */
void	*ft_memset(void *ptr, int c, size_t n)
{
	while (n--)
		*((unsigned char *)(ptr + n)) = c;
	return (ptr);
}

/**
 * Allocates and zeroes memory for an array of elements.
 *
 * @param nmemb Number of elements
 * @param size Size of each element
 * @return Pointer to the allocated memory, or NULL if allocation fails
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_bytes;

	total_bytes = nmemb * size;
	if (size && (total_bytes / size) != nmemb)
		return (NULL);
	ptr = (void *)malloc(total_bytes);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, total_bytes);
	return (ptr);
}

/**
 * Concatenates two strings into a newly allocated string.
 *
 * @param s1 First string
 * @param s2 Second string
 * @return Newly allocated string containing s1 + s2
 */
char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	join = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!join)
		return (NULL);
	i = 0;
	while (*s1)
		join[i++] = *s1++;
	while (*s2)
		join[i++] = *s2++;
	join[i] = '\0';
	return (join);
}
