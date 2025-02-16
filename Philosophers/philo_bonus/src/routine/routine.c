/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:24:06 by joao-alm          #+#    #+#             */
/*   Updated: 2025/02/16 19:30:10 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#include "philo_bonus.h"
#include "util.h"

void	*ft_monitor(void *arg)
{
	t_philo *philo;
	size_t	time;

	philo = (t_philo *)arg;
	while (1)
	{
		time = ft_time_ms();
		pthread_mutex_lock(&philo->eat);
		if (time - philo->last_meal > philo->data->die_time)
		{
			pthread_mutex_unlock(&philo->eat);
			sem_wait(philo->data->monitor.sem);
			sem_wait(philo->data->print.sem);
			printf(BOLD "%lu" RESET " Philo " BOLD "%d" RESET PINK " has died" RESET "\n",
				time - philo->data->start_time, philo->id);
			pthread_mutex_unlock(&philo->eat);
			sem_post(philo->data->stop.sem);
			exit(1) ; // Ensures the process stops
		}
		pthread_mutex_unlock(&philo->eat);
		pthread_mutex_lock(&philo->eat);
		if (philo->data->n_meals != -1 && philo->meal_count >= philo->data->n_meals)
		{
			pthread_mutex_unlock(&philo->eat);
			sem_wait(philo->data->monitor.sem);
			sem_wait(philo->data->print.sem);
			printf(BOLD "%lu" RESET " Philo " BOLD "%d" RESET PINK " is full" RESET "\n",
				time - philo->data->start_time, philo->id);
			pthread_mutex_unlock(&philo->eat);
			sem_post(philo->data->stop.sem);
			exit(1) ; // Ensures the process stops
		}
		pthread_mutex_unlock(&philo->eat);
		usleep(100);
	}
}


void	ft_print_status(t_philo *philo, const char *status, const char *colour)
{
	sem_wait(philo->data->print.sem);
	printf(BOLD "%lu" RESET " Philo " BOLD "%d" RESET "%s %s" RESET "\n", ft_time_ms() - philo->data->start_time, philo->id, colour, status);
	sem_post(philo->data->print.sem);
}

void	ft_routine(t_philo *philo)
{
	t_data		*data;
	pthread_t	monitor;

	data = philo->data;
	if (philo->id % 2 == 1)
		usleep(100);
	pthread_mutex_init(&philo->eat, NULL);
	pthread_mutex_lock(&philo->eat);
	philo->last_meal = ft_time_ms();
	pthread_mutex_unlock(&philo->eat);
	pthread_create(&monitor, NULL, ft_monitor, philo);
	pthread_detach(monitor);
	while (1)
	{
		sem_wait(data->forks.sem);
		ft_print_status(philo, "has taken a fork", YELLOW);
		sem_wait(data->forks.sem);
		ft_print_status(philo, "has taken a fork", YELLOW);
		pthread_mutex_lock(&philo->eat);
		philo->last_meal = ft_time_ms();
		philo->meal_count++;
		pthread_mutex_unlock(&philo->eat);
		ft_print_status(philo, "is eating", GREEN);
		usleep(data->eat_time * 1000);
		sem_post(data->forks.sem);
		usleep(100);
		sem_post(data->forks.sem);
		ft_print_status(philo, "is sleeping", PINK);
		usleep(data->sleep_time * 1000);
		ft_print_status(philo, "is thinking", PURPLE);
	}
}
