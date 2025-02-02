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

int	ft_handle_args(t_data *data, int ac, char **av)
{
	int	valid;

	data->n_philos = (int)ft_atoll_valid(av[1], 1, 200, &valid);
	if (!valid)
		return(E_INVALID_PHILO);
	data->die_time = ft_atoll_valid(av[2], 1, INT_MAX, &valid);
	if (!valid)
		return(E_INVALID_DIE);
	data->eat_time = ft_atoll_valid(av[3], 1, INT_MAX, &valid);
	if (!valid)
		return(E_INVALID_EAT);
	data->sleep_time = ft_atoll_valid(av[4], 1, INT_MAX, &valid);
	if (!valid)
		return(E_INVALID_SLEEP);
	data->n_meals = -1;
	if (data->n_philos > 1 && ac == 6)
	{
		data->n_meals = (int)ft_atoll_valid(av[5], 0, INT_MAX, &valid);
		if (!valid)
			return(E_INVALID_MEALS);
	}
	return (0);
}

int	ft_init_data(t_data *data, int ac, char **av)
{
	int				i;
	int				error;

	error = ft_handle_args(data, ac, av);
	if (error)
		return (error);
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
