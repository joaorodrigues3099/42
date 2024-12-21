/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:17:45 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/25 16:17:45 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

/**
 * Gets a previous Malloc, creates a bigger,
 * copies the values from to the new Malloc and frees the previous one.
 *
 * @param src Malloc to realloc.
 * @param old_size Size of the Malloc to resize.
 * @param new_size Size of the Malloc.
 * @return Returns a pointer for the reallocated address.
 */
void	*ft_realloc(void *src, size_t old_size, size_t new_size)
{
	void	*realloc;

	if (!new_size)
		return (NULL);
	realloc = (void *)malloc(new_size);
	if (!realloc)
		return (NULL);
	realloc = ft_memcpy(realloc, src, old_size);
	if (!realloc)
		return (NULL);
	free (src);
	return (realloc);
}