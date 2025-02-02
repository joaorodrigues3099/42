/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:24:54 by joao-alm          #+#    #+#             */
/*   Updated: 2025/01/27 14:24:54 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include "error.h"
#include "philosophers.h"

int	ft_init_philosopher(t_data *data, const int i)
{
	t_philo *philo;

	philo = &data->philo[i];
	philo->id = i + 1;
	pthread_mutex_init(&philo->left_fork, NULL);
	if (i == data->n_philos - 1)
		philo->right_fork = &data->philo[0].left_fork;
	else
		philo->right_fork = &data->philo[i + 1].left_fork;
	philo->meals_eaten = 0;
	philo->last_meal = data->start_time;
	philo->data = data;
	return (0);
}

int	ft_init_data(t_data *data, int ac, char **av)
{
	int				i;

	data->philo = malloc(sizeof(t_philo) * data->n_philos);
	if (!data->philo)
		return (E_MEMORY_ALLOCATION);
	pthread_mutex_init(&data->mutex, NULL);
	data->start_time = ft_time_ms();
	data->death = 0;
	data->full = 0;
	i = -1;
	while (++i < data->n_philos)
		ft_init_philosopher(data, i);
	return (0);
}
