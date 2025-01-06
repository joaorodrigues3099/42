/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:19:31 by ctirapo-          #+#    #+#             */
/*   Updated: 2024/07/31 22:03:59 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*grow_buffer(char *buffer, size_t *buffer_size, size_t *result_size)
{
	char	*new_buffer;

	new_buffer = (char *)malloc(*buffer_size * 2);
	if (!new_buffer)
		exit_with_error("Memory allocation error");
	my_memcpy(new_buffer, buffer, *result_size);
	free(buffer);
	*buffer_size *= 2;
	return (new_buffer);
}

char	*ft_strdup(char *src, int n)
{
	int		i;
	char	*dst;

	dst = (char *)malloc(n + 1);
	if (!dst)
		exit_with_error("Memory allocation error");
	i = 0;
	while (src[i] && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\n';
	return (dst);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	*my_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}
