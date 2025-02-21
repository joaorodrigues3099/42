/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:47:46 by joao-alm          #+#    #+#             */
/*   Updated: 2025/02/16 13:47:50 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "philo_bonus.h"
#include "util.h"

void	ft_init_semaphore(t_dtable *dtable, sem_t **sem, const char *name, const int flag)
{
	sem_unlink(name);
	*sem = sem_open(name, O_CREAT, 0644, flag);
	if (*sem == SEM_FAILED)
		ft_exit(E_SEM_OPEN, dtable);
}

void	ft_init_philos(t_dtable *data)
{
	int i;
	t_philo *philo;

	i = -1;
	while (++i < data->philo_count)
	{
		philo = &data->philo[i];
		philo->id = i + 1;
		pthread_mutex_init(&philo->meal_mutex, NULL);
		philo->meal_count = 0;
		philo->stop = 0;
		philo->dtable = data;
	}
}

void	ft_init_dtable(int ac, char **av, t_dtable *dtable)
{
	int i;

	dtable->philo = NULL;
	dtable->philo_count = (int)ft_atoi_v(av[1]);
	dtable->philo = malloc(dtable->philo_count * sizeof(t_philo));
	if (!dtable->philo)
		ft_exit(E_MEM_ALLOC, dtable);
	i = -1;
	ft_init_semaphore(dtable, &dtable->forks, "/forks", dtable->philo_count);
	ft_init_semaphore(dtable, &dtable->print, "/print", 1);
	ft_init_semaphore(dtable, &dtable->full, "/full", 0);
	ft_init_semaphore(dtable, &dtable->stop, "/stop", 0);
	dtable->die_time = ft_atoi_v(av[2]);
	dtable->eat_time = ft_atoi_v(av[3]);
	dtable->sleep_time = ft_atoi_v(av[4]);
	dtable->min_meals = -1;
	if (ac > 5)
		dtable->min_meals = (int)ft_atoi_v(av[5]);
	ft_init_philos(dtable);
	dtable->start_time = ft_time_ms(0);
}
