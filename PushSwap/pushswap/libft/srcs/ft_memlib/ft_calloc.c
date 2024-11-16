/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:58:39 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/23 18:58:43 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memlib.h"
#include <stdlib.h>

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
	ft_bzero(ptr, total_bytes);
	return (ptr);
}
