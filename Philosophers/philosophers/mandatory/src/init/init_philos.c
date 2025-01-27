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

#include <stdlib.h>

#include "error.h"
#include "philosophers.h"

void	ft_init_mutex(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philos)
		pthread_mutex_init(&data->fork[i], NULL);
}

void	ft_init_philos(t_data *data)
{
	int	i;

	data->philo = malloc(sizeof(t_philo) * data->n_philos);
	if (!data->philo)
		ft_print_error(E_MEMORY_ALLOCATION);
	ft_init_mutex(data);
	i = 0;
	while (i < data->n_philos)
	{
		if (pthread_create(&data->philo[i].thread, NULL, ft_routine, NULL))
			exit (E_FAILED_CREATE_THREAD);
		data->philo[i].id = i;
		data->philo[i].left_fork = &data->fork[i];
		if (i == data->n_philos - 1)
			data->philo[i].right_fork = &data->fork[0];
		else
			data->philo[i].right_fork = &data->fork[i + 1];
		i++;
	}
}
