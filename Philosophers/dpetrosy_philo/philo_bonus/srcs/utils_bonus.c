/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:38:47 by dapetros          #+#    #+#             */
/*   Updated: 2024/03/16 18:38:50 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

void	error_message(char *text, int signal)
{
	if (text)
		write(2, text, ft_strlen(text) + 1);
	exit(signal);
}

void	destroy_all(t_engine *engine, char *str, bool isParentProc, int signal)
{
	int	i;

	i = -1;
	if (isParentProc)
	{
		while (++i < engine->philo_count)
			if (engine->proc_ids[i] != -1)
				kill(engine->proc_ids[i], SIGKILL);
	}
	if (engine->sems->die_sem != SEM_FAILED)
		sem_close(engine->sems->die_sem);
	if (engine->sems->fork_sem != SEM_FAILED)
		sem_close(engine->sems->fork_sem);
	if (engine->sems->meal_sem != SEM_FAILED)
		sem_close(engine->sems->meal_sem);
	if (engine->sems->write_sem != SEM_FAILED)
		sem_close(engine->sems->write_sem);
	i = -1;
	while (++i < engine->philo_count)
		free(engine->philos[i]);
	free(engine->sems);
	free(engine->philos);
	free(engine->proc_ids);
	free(engine);
	error_message(str, signal);
}

void	print_action(t_philo *philo, char *action)
{
	size_t	time;

	sem_wait(philo->sems->write_sem);
	time = get_current_time() - philo->times.born_time;
	printf(GREEN"[%ld]"RESET" %d %s\n", time, philo->id, action);
	sem_post(philo->sems->write_sem);
}

size_t	get_current_time(void)
{
	t_timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		error_message("[gettimeofday ERROR]\n", 1);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(size_t mls)
{
	size_t	start;

	start = get_current_time();
	while (get_current_time() - start < mls)
		usleep(100);
}
