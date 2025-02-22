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

#include "philo_bonus.h"
#include <limits.h>
#include <sys/time.h>

size_t	ft_time_ms(const size_t start_time)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000 + tv.tv_usec / 1000) - start_time);
}

long	ft_atoi_v(const char *str)
{
	int		sign;
	long	res;

	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign *= -1;
	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		if (res > INT_MAX)
			break ;
		str++;
	}
	return (res * sign);
}
