/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:44:54 by joao-alm          #+#    #+#             */
/*   Updated: 2025/02/03 22:23:10 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "philosophers.h"

int	ft_stop(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->stop_mutex);
	pthread_mutex_lock(&philo->data->meal);
	if (philo->data->death || philo->data->n_full == philo->data->n_philos)
	{
		pthread_mutex_unlock(&philo->data->meal);
		pthread_mutex_unlock(&philo->data->stop_mutex);
		return (-1);
	}
	if (ft_time_ms() - philo->last_meal > philo->data->times.die)
		philo->data->death = philo->id;
	if (philo->meals_eaten == philo->data->n_meals)
		philo->data->n_full++;
	if (philo->data->n_full == philo->data->n_philos)
	{
		pthread_mutex_unlock(&philo->data->meal);
		pthread_mutex_unlock(&philo->data->stop_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->meal);
	pthread_mutex_unlock(&philo->data->stop_mutex);
	return (0);
}

int	ft_print_status(t_philo *philo, const char *msg)
{
	if (ft_stop(philo))
		return (-1);
	pthread_mutex_lock(&philo->data->print);
	if (ft_stop(philo))
	{
		pthread_mutex_unlock(&philo->data->print);
		return (-1);
	}
	printf("%ld %d %s\n", ft_time_ms() - philo->data->times.start, philo->id, msg);
	pthread_mutex_unlock(&philo->data->print);
	return (0);
}

void    *ft_routine(void *ptr)
{
	t_philo *philo;
	pthread_mutex_t *first_fork;
	pthread_mutex_t *second_fork;

	philo = (t_philo *)ptr;

	first_fork = &philo->left_fork;
	second_fork = philo->right_fork;
//	if (philo->id == philo->data->n_philos - 1)
//	{
//		second_fork = &philo->left_fork;
//		first_fork = philo->right_fork;
//	}
	if (philo->id % 2 == 1)
		usleep(1000);
	while (1)
	{
		if (ft_stop(philo))
			break ;
		pthread_mutex_lock(first_fork);
		if (ft_print_status(philo, "has taken a fork") != 0)
		{
			pthread_mutex_unlock(first_fork);
			break ;
		}
		if (philo->data->n_philos == 1)
		{
			ft_usleep(philo->data->times.die);
			ft_stop(philo);
			pthread_mutex_unlock(first_fork);
			break ;
		}
		pthread_mutex_lock(second_fork);
		if (ft_print_status(philo, "has taken a fork") != 0)
		{
			pthread_mutex_unlock(first_fork);
			pthread_mutex_unlock(second_fork);
			break ;
		}

		pthread_mutex_lock(&philo->data->meal);
		philo->meals_eaten++;
		philo->last_meal = ft_time_ms();
		pthread_mutex_unlock(&philo->data->meal);

		if (ft_print_status(philo, "is eating") != 0)
		{
			pthread_mutex_unlock(first_fork);
			pthread_mutex_unlock(second_fork);
			break ;
		}
		ft_usleep(philo->data->times.eat);
		pthread_mutex_unlock(first_fork);
		pthread_mutex_unlock(second_fork);
		if (ft_print_status(philo, "is sleeping") != 0)
			break ;
		ft_usleep(philo->data->times.sleep);
		if (ft_print_status(philo, "is thinking") != 0)
			break ;
		usleep(1000);
	}
	return (NULL);
}
