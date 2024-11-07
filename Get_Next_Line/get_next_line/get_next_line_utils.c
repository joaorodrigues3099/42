/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <support@toujoustudios.net>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:42:05 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/05 15:42:05 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * Counts the length of the given string.
 *
 * @param s String to get size of
 * @return Returns string size or
 * seg fault if the pointer is null
 */
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * Fills the first 'n' bytes of the area pointed by 's'
 * with the given 'c' character.
 *
 * @param s Pointer to memory area
 * @param c Character to set
 * @param n Number of bytes to set
 * @return Returns the given Address
 */
void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = (unsigned char)c;
	return (s);
}

/**
 * Allocates memory for an array of pointers.
 *
 * @param nmemb Number of elements
 * @param size Size of each element
 * @return Returns newly allocated memory,\n
 * Or NULL on overflow or failed allocation.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_bytes;

	total_bytes = nmemb * size;
	if (size && ((total_bytes / size) != nmemb))
		return (NULL);
	ptr = malloc(total_bytes);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, total_bytes);
	return (ptr);
}

/**
 * Concatenates two strings into a newly allocated string.
 *
 * @param s1 First string.
 * @param s2 Second string.
 * @return Newly allocated concatenated string
 */
char	*ft_strjoin(char const *s1, char const *s2)
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
