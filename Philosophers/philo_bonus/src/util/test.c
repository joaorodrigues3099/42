/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 14:45:18 by joao-alm          #+#    #+#             */
/*   Updated: 2025/02/16 14:45:23 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include <stdio.h>

void	ft_print_sem(t_sem *sem)
{
	if (sem->sem)
		printf("Semaphore %s is ON. address: %p\n", sem->name, sem->sem);
	else
		printf("sem_t %s is NULL\n", sem->name);
}

void	ft_print_data(t_data *data)
{
	int	i;

	printf("---------------PRINT_DATA---------------\n");
	printf("%d Philos\n", data->philo_count);
	i = -1;
	if (data->philo)
		while (++i < data->philo_count)
			printf("Philo %d's pid: %d\n", data->philo[i].id, data->philo[i].pid);
	else
		printf("*philo_pid is NULL\n");
	ft_print_sem(&data->forks);
	ft_print_sem(&data->print);
	ft_print_sem(&data->monitor);
	printf("Die_Time: %zu\n", data->die_time);
	printf("Eat_Time: %zu\n", data->eat_time);
	printf("Sleep_Time: %zu\n", data->sleep_time);
	if (data->n_meals == -1)
		printf("N_Meals: infinite\n");
	else
		printf("N_Meals: %d\n", data->n_meals);
	ft_print_sem(&data->stop);
	printf("-------------------END------------------\n");
}
