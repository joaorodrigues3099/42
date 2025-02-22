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

#include "philo_bonus.h"
#include "util.h"
#include <pthread.h>
#include <stdlib.h>

void	ft_free_sem(sem_t *sem, const char *name)
{
	sem_close(sem);
	sem_unlink(name);
	sem = NULL;
}

int	ft_exit(const int err_no, t_dtable *dtable)
{
	int	i;

	if (dtable)
	{
		if (dtable->forks)
			ft_free_sem(dtable->forks, "/forks");
		if (dtable->print)
			ft_free_sem(dtable->print, "/print");
		if (dtable->full)
			ft_free_sem(dtable->full, "/full");
		if (dtable->stop)
			ft_free_sem(dtable->stop, "/stop");
		if (dtable->philo)
		{
			i = -1;
			while (++i < dtable->philo_count)
				if (dtable->philo[i].meal_mutex_init)
					pthread_mutex_destroy(&dtable->philo[i].meal_mutex);
			free(dtable->philo);
		}
	}
	ft_print_error(err_no);
	exit(err_no);
}
