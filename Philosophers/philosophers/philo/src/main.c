/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 08:32:52 by joao-alm          #+#    #+#             */
/*   Updated: 2025/01/27 14:16:34 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "error.h"
#include "philosophers.h"
#include <sys/time.h>

int	ft_monitor(t_philo *philo)
{
	unsigned long long time;

	pthread_mutex_lock(&philo->data->mutex);
	time = ft_time_ms();
	if (time - philo->last_meal > philo->data->die_time)
	{
		philo->data->death = 1;
		pthread_mutex_unlock(&philo->left_fork);
		pthread_mutex_unlock(&philo->data->mutex);
		usleep(100);
		printf("%s%lld %d died\n%s", BOLD, time - philo->data->start_time, philo->id, RESET);
		return (0);
	}
	if (philo->meals_eaten == philo->data->n_meals)
		philo->data->full++;
	if (philo->data->full == philo->data->n_philos)
	{
		pthread_mutex_unlock(&philo->left_fork);
		pthread_mutex_unlock(&philo->data->mutex);
		usleep(100);
		printf("%sEvery philosopher has eaten %d time%s\n", BOLD, philo->meals_eaten, RESET);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->mutex);
	return (1);
}

int	main(int ac, char **av)
{
	int		error;
	t_data	data;
	int		i;

	if (ac < 5 || ac > 6)
		return (ft_print_error(E_INVALID_FORMAT));
	error = ft_init_data(&data, ac, av);
	if (error)
		return (ft_print_error(error));
	i = -1;
	while (++i < data.n_philos)
		pthread_create(&data.philo[i].thread, NULL, ft_routine, &data.philo[i]);
	i = 0;
	while (i < data.n_philos && ft_monitor(&data.philo[i]))
	{
		i++;
		if (i == data.n_philos)
			i = 0;
	}
	i = -1;
	while (++i < data.n_philos)
		pthread_join(data.philo[i].thread, NULL);
	free(data.philo);
	return (0);
}
