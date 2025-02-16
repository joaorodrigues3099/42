/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:51:22 by joao-alm          #+#    #+#             */
/*   Updated: 2025/02/07 14:51:36 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include "philo_bonus.h"

void	ft_free_sem(t_sem *sem)
{
	sem_close(sem->sem);
	sem_unlink(sem->name);
	sem->sem = NULL;
}

int	ft_exit(const int err_no, t_data *data)
{
	if (data)
	{
		if (data->philo)
			free(data->philo);
		if (data->forks.sem)
			ft_free_sem(&data->forks);
		if (data->print.sem)
			ft_free_sem(&data->print);
		if (data->monitor.sem)
			ft_free_sem(&data->monitor);
		if (data->stop.sem)
			ft_free_sem(&data->stop);

	}
	ft_print_error(err_no);
	exit(err_no);
}
