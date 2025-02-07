/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:44:54 by joao-alm          #+#    #+#             */
/*   Updated: 2025/02/06 17:20:24 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colour.h"
#include "error.h"
#include "philosophers.h"
#include <stdio.h>
#include <unistd.h>

int	ft_take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	if (ft_print_status(philo, YELLOW "has taken a fork" RESET) != 0)
	{
		pthread_mutex_unlock(&philo->left_fork);
		return (-1);
	}
	if (philo->data->n_philos == 1)
	{
		usleep(philo->data->die_time * 1000);
		ft_stop_routine(philo);
		pthread_mutex_unlock(&philo->left_fork);
		return (-1);
	}
	pthread_mutex_lock(philo->right_fork);
	if (ft_print_status(philo, YELLOW "has taken a fork" RESET) != 0)
	{
		pthread_mutex_unlock(&philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (-1);
	}
	return (0);
}

int	ft_eat(t_philo *philo)
{
	if (ft_stop_routine(philo))
		return (-1);
	if (ft_take_forks(philo))
		return (-1);
	pthread_mutex_lock(&philo->data->meal);
	philo->meals_eaten++;
	philo->last_meal = ft_time_ms();
	pthread_mutex_unlock(&philo->data->meal);
	if (ft_print_status(philo, GREEN "is eating" RESET) != 0)
	{
		pthread_mutex_unlock(&philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (-1);
	}
	usleep(philo->data->eat_time * 1000);
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (0);
}

void	*ft_routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		usleep(100);
	pthread_mutex_lock(&philo->data->meal);
	philo->last_meal = ft_time_ms();
	pthread_mutex_unlock(&philo->data->meal);
	while (1)
	{
		if (ft_eat(philo))
			break ;
		if (ft_print_status(philo, PINK "is sleeping" RESET) != 0)
			break ;
		usleep(philo->data->sleep_time * 1000);
		if (ft_print_status(philo, PURPLE "is thinking" RESET) != 0)
			break ;
	}
	return (NULL);
}

int	ft_start_routine(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philos)
	{
		if (pthread_create(&data->philo[i].thread, NULL, ft_routine,
				(void *)&data->philo[i]) != 0)
			return (E_CREATE_THREAD);
		data->philo[i].thread_init = 1;
	}
	return (0);
}
