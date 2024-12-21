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

#include "../../includes/memlib.h"

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
	if (src)
	{
		free (src);
		src = NULL;
	}
	return (realloc);
}