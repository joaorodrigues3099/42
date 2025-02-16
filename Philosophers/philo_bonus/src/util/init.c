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
#include <stdio.h>
#include <unistd.h>
#include <wait.h>

#include "philo_bonus.h"
#include "util.h"

void	ft_sanitize_data(t_data *data)
{
	data->philo = NULL;
	data->forks.sem = NULL;
	data->forks.name = NULL;
	data->print.sem = NULL;
	data->print.name = NULL;
	data->monitor.sem = NULL;
	data->monitor.name = NULL;
	data->stop.sem = NULL;
	data->stop.name = NULL;
}

void	ft_init_semaphore(t_data *data, t_sem *sem, char *name, const int sem_value)
{
	sem_unlink(name);
	sem->name = name;
	sem->sem = sem_open(sem->name, O_CREAT, 0644, sem_value);
	if (sem->sem == SEM_FAILED)
		ft_exit(E_SEM_OPEN, data);
}

void	ft_init_philo(t_data *data)
{
	int	i;
	int	pid;

	i = -1;
	pid = 0;
	while (++i < data->philo_count)
	{
		data->philo[i].id = i + 1;
		data->philo[i].data = data;
		data->philo[i].meal_count = 0;
		pid = fork();
		if (pid == 0)
		{
			ft_routine(&data->philo[i]);
			exit (0);
		}
		data->philo[i].pid = pid;
	}
	sem_wait(data->stop.sem);
	i = -1;
	while (++i < data->philo_count)
		kill(data->philo[i].pid, SIGKILL);
	sem_close(data->forks.sem);
	sem_close(data->monitor.sem);
	sem_close(data->print.sem);
	sem_close(data->stop.sem);
}

void	ft_init_data(int ac, char **av, t_data *data)
{
	data->philo_count = (int)ft_atoi_v(av[1]);
	data->philo = malloc(data->philo_count * sizeof(t_philo));
	if (!data->philo)
		ft_exit(E_MEM_ALLOC, data);
	ft_init_semaphore(data, &data->forks, "/forks", data->philo_count);
	ft_init_semaphore(data, &data->print, "/print", 1);
	ft_init_semaphore(data, &data->monitor, "/monitor", 1);
	ft_init_semaphore(data, &data->stop, "/stop", 0);
	data->die_time = ft_atoi_v(av[2]);
	data->eat_time = ft_atoi_v(av[3]);
	data->sleep_time = ft_atoi_v(av[4]);
	data->n_meals = -1;
	if (ac > 5)
		data->n_meals = (int)ft_atoi_v(av[5]);
	data->start_time = ft_time_ms();
}

void	ft_init(int ac, char **av, t_data *data)
{
	ft_sanitize_data(data);
	ft_init_data(ac, av, data);
	ft_init_philo(data);
}
