/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:51:22 by joao-alm          #+#    #+#             */
/*   Updated: 2025/02/07 14:51:36 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "util.h"
#include <stdlib.h>

int	ft_exit(t_data *data, int exit_code)
{
	int	i;

	if (data->philo)
	{
		i = -1;
		while (++i < data->n_philos)
			if (data->philo[i].thread_init
				&& pthread_join(data->philo[i].thread, NULL) != 0)
				pthread_detach(data->philo[i].thread);
		i = -1;
		while (++i < data->n_philos)
			if (data->philo[i].left_init)
				pthread_mutex_destroy(&data->philo[i].left_fork);
		free(data->philo);
	}
	if (data->print_init)
		pthread_mutex_destroy(&data->print);
	if (data->meal_init)
		pthread_mutex_destroy(&data->meal);
	if (data->monitor_init)
		pthread_mutex_destroy(&data->monitor);
	ft_print_error(exit_code);
	return (exit_code);
}
