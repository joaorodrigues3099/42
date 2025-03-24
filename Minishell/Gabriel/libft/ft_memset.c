/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:46:46 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/10/21 18:20:44 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int d, size_t n)
{
	size_t			j;
	unsigned char	*p;

	p = (unsigned char *)s;
	j = 0;
	while (j < n)
	{
		p[j] = (unsigned char)d;
		j++;
	}
	return (s);
}
