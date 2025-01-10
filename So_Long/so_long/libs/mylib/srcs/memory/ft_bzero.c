/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 22:58:03 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/18 22:58:05 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_memory.h"

/**
 * Fills the first 'n' bytes of the area pointed by 's'
 * with the NULL character.
 *
 * @param s Pointer to memory area
 * @param n Number of bytes to set
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
