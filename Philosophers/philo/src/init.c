/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:24:54 by joao-alm          #+#    #+#             */
/*   Updated: 2025/02/07 10:27:17 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include "philosophers.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Initializes a philosopher's attributes and forks.
 *
 * @param data Pointer to the main data structure.
 * @param i Index of the philosopher to initialize.
 * @return 0 on success, -1 on failure.
 */
int	ft_init_philosopher(t_data *data, const int i)
{
	t_philo	*philo;

	philo = &data->philo[i];
	philo->thread_init = 0;
	philo->left_init = 0;
	philo->id = i + 1;
	if (pthread_mutex_init(&philo->left_fork, NULL) != 0)
		return (-1);
	philo->left_init = 1;
	if (i == data->n_philos - 1)
		philo->right_fork = &data->philo[0].left_fork;
	else
		philo->right_fork = &data->philo[i + 1].left_fork;
	philo->meals_eaten = 0;
	philo->last_meal = data->start_time;
	philo->full = 0;
	philo->data = data;
	return (0);
}

/**
 * Initializes the mutexes used in the program.
 *
 * @param data Pointer to the main data structure.
 * @return 0 on success, error code on failure.
 */
int	ft_init_data_mutex(t_data *data)
{
	data->print_init = 0;
	data->meal_init = 0;
	data->monitor_init = 0;
	if (pthread_mutex_init(&data->print, NULL) != 0)
		return (-1);
	data->print_init = 1;
	if (pthread_mutex_init(&data->meal, NULL) != 0)
		return (-1);
	data->meal_init = 1;
	if (pthread_mutex_init(&data->monitor, NULL) != 0)
		return (-1);
	data->monitor_init = 1;
	return (0);
}

/**
 * Parses and assigns command-line arguments to the main data structure.
 *
 * @param data Pointer to the main data structure.
 * @param ac Argument count.
 * @param av Argument vector.
 */
void	ft_init_data_args(t_data *data, int ac, char **av)
{
	data->n_philos = (int)ft_atoi_v(av[1]);
	data->die_time = ft_atoi_v(av[2]);
	data->eat_time = ft_atoi_v(av[3]);
	data->sleep_time = ft_atoi_v(av[4]);
	data->n_meals = -1;
	if (ac == 6)
		data->n_meals = (int)ft_atoi_v(av[5]);
}

/**
 * Initializes the main data structure, including philosophers and mutexes.
 *
 * @param data Pointer to the main data structure.
 * @param ac Argument count.
 * @param av Argument vector.
 * @return 0 on success, error code on failure.
 */
int	ft_init_data(t_data *data, int ac, char **av)
{
	int	i;

	data->philo = NULL;
	ft_init_data_args(data, ac, av);
	if (ft_init_data_mutex(data))
		return (E_MUTEX_INIT);
	data->philo = malloc(sizeof(t_philo) * data->n_philos);
	if (!data->philo)
		return (E_MEM_ALLOC);
	i = -1;
	data->start_time = ft_time_ms();
	while (++i < data->n_philos)
		if (ft_init_philosopher(data, i))
			return (E_MUTEX_INIT);
	data->n_full = 0;
	data->death = 0;
	return (0);
}
