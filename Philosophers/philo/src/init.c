/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:24:54 by joao-alm          #+#    #+#             */
/*   Updated: 2025/02/03 20:58:45 by joao-alm         ###   ########.fr       */
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
	if (pthread_mutex_init(&data->philo->left_fork, NULL) != 0)
		return (-1);
	if (i == data->n_philos - 1)
		philo->right_fork = &data->philo[0].left_fork;
	else
		philo->right_fork = &data->philo[i + 1].left_fork;
	philo->meals_eaten = 0;
	philo->last_meal = data->times.start;
	philo->data = data;
	return (0);
}

int	ft_init_data(t_data *data, int ac, char **av)
{
	int				i;

	data->n_philos = (int)ft_atoi_v(av[1]);
	data->philo = malloc(sizeof(t_philo) * data->n_philos);
	if (!data->philo)
		return (E_MEM_ALLOC);
	if (pthread_mutex_init(&data->print, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&data->meal, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&data->stop_mutex, NULL) != 0)
		return (-1);
	data->times.die = ft_atoi_v(av[2]);
	data->times.eat = ft_atoi_v(av[3]);
	data->times.sleep = ft_atoi_v(av[4]);
	data->times.start = ft_time_ms();
	data->n_meals = -1;
	if (ac == 6)
		data->n_meals = (int) ft_atoi_v(av[5]);
	i = -1;
	while (++i < data->n_philos)
		if (ft_init_philosopher(data, i) != 0)
			return (-1);
	data->n_full = 0;
	data->death = 0;
	return (0);
}
