/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:00:29 by joao-alm          #+#    #+#             */
/*   Updated: 2025/02/06 17:40:11 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colour.h"
#include "error.h"
#include "philosophers.h"
#include <stdio.h>

void	ft_death(t_data *data)
{
	int		i;
	size_t	time;

	time = ft_time_ms();
	i = -1;
	while (++i < data->n_philos)
	{
		if (time - data->philo[i].last_meal > data->die_time)
		{
			data->death = data->philo[i].id;
			return ;
		}
	}
}

void	ft_full(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philos)
	{
		if (data->philo[i].meals_eaten == data->n_meals && !data->philo[i].full)
		{
			data->n_full++;
			data->philo[i].full = 1;
		}
	}
}

void	ft_monitor(t_data *data)
{
	while (1)
	{
		pthread_mutex_lock(&data->monitor);
		pthread_mutex_lock(&data->meal);
		ft_death(data);
		ft_full(data);
		pthread_mutex_unlock(&data->meal);
		if (data->death || data->n_full == data->n_philos)
		{
			pthread_mutex_unlock(&data->monitor);
			usleep(1000);
			pthread_mutex_lock(&data->print);
			if (data->death)
				printf("[%ld] " BOLD "%d " PINK "died\n" RESET, ft_time_ms()
					- data->start_time, data->death);
			else
				printf(BOLD "Everyone ate" GREEN
					" %d " RESET BOLD "times\n" RESET, data->n_meals);
			pthread_mutex_unlock(&data->print);
			return ;
		}
		pthread_mutex_unlock(&data->monitor);
		usleep(100);
	}
}
