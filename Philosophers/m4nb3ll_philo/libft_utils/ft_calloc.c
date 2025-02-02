/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 00:07:36 by abelayad          #+#    #+#             */
/*   Updated: 2023/05/29 15:16:39 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	tmp = malloc(size * count);
	if (!tmp)
		return (NULL);
	return (memset(tmp, 0, size * count));
}
