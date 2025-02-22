/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:24:06 by joao-alm          #+#    #+#             */
/*   Updated: 2025/02/19 08:51:27 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "util.h"
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void	*ft_all_full(void *arg)
{
	t_dtable	*dtable;
	int			i;

	dtable = (t_dtable *)arg;
	i = -1;
	while (++i < dtable->philo_count)
	{
		sem_wait(dtable->full);
		if (dtable->break_full)
			return (NULL);
	}
	sem_wait(dtable->print);
	printf(BOLD "Everyone ate " GREEN "%d" RESET BOLD " times" RESET "\n",
		dtable->min_meals);
	sem_post(dtable->stop);
	return (NULL);
}

void	ft_kill(t_dtable *dtable)
{
	int	i;

	dtable->break_full = 1;
	sem_post(dtable->full);
	i = -1;
	while (++i < dtable->philo_count)
	{
		if (kill(dtable->philo[i].pid, 0) == 0)
			kill(dtable->philo[i].pid, SIGKILL);
		waitpid(dtable->philo[i].pid, NULL, 0);
	}
}

void	ft_fork(t_dtable *dtable)
{
	pthread_t	all_full;
	int			i;
	int			pid;

	if (pthread_create(&all_full, NULL, ft_all_full, dtable) != 0)
		ft_exit(E_CREATE_THREAD, dtable);
	pthread_detach(all_full);
	i = -1;
	while (++i < dtable->philo_count)
	{
		pid = fork();
		if (pid == 0)
		{
			ft_philo(&dtable->philo[i]);
			exit(0);
		}
		dtable->philo[i].pid = pid;
	}
	sem_wait(dtable->stop);
	usleep(100);
	ft_kill(dtable);
}
