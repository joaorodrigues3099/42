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

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>

#include "../include/philo_bonus.h"
#include "../include/util.h"

void	*ft_all_full(void *arg)
{
	t_dtable	*dtable;
	int i;

	dtable = (t_dtable *)arg;
	i = -1;
	while (++i < dtable->philo_count)
		sem_wait(dtable->full);
	sem_wait(dtable->print);
	printf("Everyone ate %d times\n", dtable->min_meals);
	sem_post(dtable->stop);
	return (NULL);
}

void	ft_fork(t_dtable *dtable)
{
	int i;
	int pid;

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
	pthread_create(&dtable->all_full, NULL, ft_all_full, dtable);
	pthread_detach(dtable->all_full);
	sem_wait(dtable->stop);
	usleep(100);
	for (i = 0; i < dtable->philo_count; i++)
	{
		kill(dtable->philo[i].pid, SIGKILL);
		waitpid(dtable->philo[i].pid, NULL, 0);
	}

	ft_exit(0, dtable);
}
