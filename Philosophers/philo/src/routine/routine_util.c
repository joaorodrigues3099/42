/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:43:47 by joao-alm          #+#    #+#             */
/*   Updated: 2025/02/07 14:45:32 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "colour.h"
#include <stdio.h>

static void	ft_print_colored(size_t time, int id, const char *msg)
{
	printf("[%ld] " BOLD "%d " RESET "%s\n", time, id, msg);
}

int	ft_print_status(t_philo *philo, const char *msg)
{
	if (ft_stop_routine(philo))
		return (-1);
	pthread_mutex_lock(&philo->data->print);
	ft_print_colored(ft_time_ms() - philo->data->start_time, philo->id, msg);
	pthread_mutex_unlock(&philo->data->print);
	return (0);
}

int	ft_stop_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->monitor);
	if (philo->data->death || philo->data->n_full == philo->data->n_philos)
	{
		pthread_mutex_unlock(&philo->data->monitor);
		return (-1);
	}
	pthread_mutex_unlock(&philo->data->monitor);
	return (0);
}
