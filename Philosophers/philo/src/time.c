/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:22:07 by joao-alm          #+#    #+#             */
/*   Updated: 2025/02/03 14:22:09 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <unistd.h>
#include <sys/time.h>

size_t	ft_time_ms()
{
	struct timeval	tv;
	size_t	seconds;
	size_t	microseconds;

	gettimeofday(&tv, NULL);
	seconds = tv.tv_sec;
	microseconds = tv.tv_usec;
	return (seconds * 1000 + microseconds / 1000);
}

void	ft_usleep(size_t mls)
{
	size_t	start;

	start = ft_time_ms();
	while (ft_time_ms() - start < mls)
		usleep(500);
}
