/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:27:15 by joao-alm          #+#    #+#             */
/*   Updated: 2025/02/17 18:27:19 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../include/philo_bonus.h"
#include "../include/util.h"

void	ft_print_status(t_philo *philo, const char *status)
{
	sem_wait(philo->dtable->print);
	printf("%zu %d %s\n", ft_time_ms(philo->dtable->start_time), philo->id, status);
	sem_post(philo->dtable->print);
}


void	*ft_philo_monitor(void *arg)
{
	t_philo	*philo;
	int		is_full;

	philo = (t_philo *)arg;
	is_full = 0;
	while (1)
	{
		pthread_mutex_lock(&philo->meal_mutex);
		if (ft_time_ms(philo->dtable->start_time) - philo->last_meal_time > philo->dtable->die_time)
		{
			pthread_mutex_unlock(&philo->meal_mutex);
			sem_post(philo->dtable->stop);
			sem_wait(philo->dtable->print);
			printf("%zu %d %s\n", ft_time_ms(philo->dtable->start_time), philo->id, "has died");
			exit (0);
		}
		if (!is_full && philo->dtable->min_meals != -1 && philo->meal_count == philo->dtable->min_meals)
		{
			is_full = 1;
			sem_post(philo->dtable->full);
		}
		pthread_mutex_unlock(&philo->meal_mutex);
		usleep(100);
	}
}

void	ft_philo(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(100);
	philo->last_meal_time = (int)ft_time_ms(philo->dtable->start_time);
	pthread_create(&philo->monitor, NULL, ft_philo_monitor, philo);
	pthread_detach(philo->monitor);
	while (1)
	{
		sem_wait(philo->dtable->forks);
		ft_print_status(philo, "has taken a fork");
		sem_wait(philo->dtable->forks);
		ft_print_status(philo, "has taken a fork");
		pthread_mutex_lock(&philo->meal_mutex);
		philo->last_meal_time = (int)ft_time_ms(philo->dtable->start_time);
		philo->meal_count += 1;
		pthread_mutex_unlock(&philo->meal_mutex);
		ft_print_status(philo, "is eating");
		usleep(philo->dtable->eat_time * 1000);
		sem_post(philo->dtable->forks);
		sem_post(philo->dtable->forks);
		ft_print_status(philo, "is sleeping");
		usleep(philo->dtable->sleep_time * 1000);
		ft_print_status(philo, "is thinking");
	}
}
