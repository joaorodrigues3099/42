/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:30:38 by abelayad          #+#    #+#             */
/*   Updated: 2023/05/30 19:38:01 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Divides the sleep into smaller parts for more accuracy
void	ft_usleep(uint64_t milli)
{
	uint64_t	now;
	uint64_t	elapsed;

	now = ft_now_ms();
	elapsed = ft_now_ms();
	while (elapsed - now < milli)
	{
		usleep(333);
		elapsed = ft_now_ms();
	}
}
