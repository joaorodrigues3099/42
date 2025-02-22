/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:27:15 by joao-alm          #+#    #+#             */
/*   Updated: 2025/02/22 08:23:51 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "util.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void	ft_print_status(const t_philo *philo, const char *status)
{
	sem_wait(philo->dtable->print);
	printf("[%ld] " BOLD "%d " RESET "%s\n",
		ft_time_ms(philo->dtable->start_time), philo->id, status);
	sem_post(philo->dtable->print);
}

void	ft_full_monitor(const t_philo *philo, int *full)
{
	if (philo->dtable->min_meals != -1
		&& philo->meal_count == philo->dtable->min_meals)
	{
		*full = 1;
		sem_post(philo->dtable->full);
	}
}

void	*ft_philo_monitor(void *arg)
{
	t_philo	*philo;
	int		full;

	philo = (t_philo *)arg;
	full = 0;
	while (1)
	{
		pthread_mutex_lock(&philo->meal_mutex);
		if (ft_time_ms(philo->dtable->start_time)
			- philo->last_meal_time > philo->dtable->die_time)
		{
			pthread_mutex_unlock(&philo->meal_mutex);
			sem_wait(philo->dtable->print);
			printf("[%ld] " BOLD "%d " RESET "%s\n",
				ft_time_ms(philo->dtable->start_time), philo->id,
				PINK "has died" RESET);
			sem_post(philo->dtable->stop);
			exit(0);
		}
		if (!full)
			ft_full_monitor(philo, &full);
		pthread_mutex_unlock(&philo->meal_mutex);
		usleep(100);
	}
}

static void	ft_routine(t_philo *philo)
{
	sem_wait(philo->dtable->forks);
	ft_print_status(philo, YELLOW "has taken a fork" RESET);
	sem_wait(philo->dtable->forks);
	ft_print_status(philo, YELLOW "has taken a fork" RESET);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_time = (int)ft_time_ms(philo->dtable->start_time);
	philo->meal_count += 1;
	pthread_mutex_unlock(&philo->meal_mutex);
	ft_print_status(philo, GREEN "is eating" RESET);
	usleep(philo->dtable->eat_time * 1000);
	sem_post(philo->dtable->forks);
	usleep(100);
	sem_post(philo->dtable->forks);
	ft_print_status(philo, PINK "is sleeping" RESET);
	usleep(philo->dtable->sleep_time * 1000);
	ft_print_status(philo, PURPLE "is thinking" RESET);
}

void	ft_philo(void *arg)
{
	t_philo		*philo;
	pthread_t	monitor;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(100);
	philo->last_meal_time = (int)ft_time_ms(philo->dtable->start_time);
	if (pthread_create(&monitor, NULL, ft_philo_monitor, philo) != 0)
	{
		sem_wait(philo->dtable->print);
		ft_print_error(E_CREATE_THREAD);
		sem_post(philo->dtable->stop);
		exit(E_CREATE_THREAD);
	}
	pthread_detach(monitor);
	while (1)
		ft_routine(philo);
}
