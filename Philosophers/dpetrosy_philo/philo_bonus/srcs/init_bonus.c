/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:37:23 by dapetros          #+#    #+#             */
/*   Updated: 2024/03/16 18:37:25 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

void	init_philos(t_engine *engine, char **argv, int count)
{
	t_philo	**philos;
	int		i;

	i = -1;
	philos = engine->philos;
	while (++i < count)
	{
		philos[i] = (t_philo *)malloc(sizeof(t_philo));
		if (!philos[i])
			destroy_all(engine, "[Malloc ERROR]\n", true, EXIT_FAILURE);
		philos[i]->id = i + 1;
		philos[i]->sems = engine->sems;
		philos[i]->times.die = ft_atoi(argv[2]);
		philos[i]->times.eat = ft_atoi(argv[3]);
		philos[i]->times.sleep = ft_atoi(argv[4]);
		philos[i]->times.last_meal = get_current_time();
		philos[i]->times.born_time = get_current_time();
		philos[i]->must_eat = -1;
		if (argv[5])
			philos[i]->must_eat = ft_atoi(argv[5]);
		philos[i]->meals_eaten = 0;
		philos[i]->philo_count = count;
	}
}

void	init_sems(t_engine *engine, t_sems *sems, int count)
{
	sems->die_sem = sem_open(DIE_SEM_NAME, O_CREAT | O_EXCL, 0644, 1);
	sems->fork_sem = sem_open(FORK_SEM_NAME, O_CREAT | O_EXCL, 0644, count);
	sems->meal_sem = sem_open(MEAL_SEM_NAME, O_CREAT | O_EXCL, 0644, 0);
	sems->write_sem = sem_open(WRITE_SEM_NAME, O_CREAT | O_EXCL, 0644, 1);
	if (sems->die_sem == SEM_FAILED || sems->fork_sem == SEM_FAILED
		|| sems->meal_sem == SEM_FAILED || sems->write_sem == SEM_FAILED)
		destroy_all(engine, "[Semaphore Open ERROR]\n", true, EXIT_FAILURE);
	if (sem_unlink(DIE_SEM_NAME) == -1 || sem_unlink(FORK_SEM_NAME) == -1
		|| sem_unlink(MEAL_SEM_NAME) == -1 || sem_unlink(WRITE_SEM_NAME) == -1)
		destroy_all(engine, "[Semaphore Unlink ERROR]\n", true, EXIT_FAILURE);
}

t_engine	*init_engine(int count)
{
	t_engine	*engine;
	t_philo		**philos;
	pid_t		*proc_ids;
	t_sems		*sems;
	int			i;

	i = -1;
	engine = (t_engine *)malloc(sizeof(t_engine));
	philos = (t_philo **)malloc(sizeof(t_philo *) * count);
	proc_ids = (pid_t *)malloc(sizeof(pid_t) * count);
	sems = (t_sems *)malloc(sizeof(t_sems));
	if (!engine || !philos || !proc_ids || !sems)
		destroy_all(engine, "[Malloc ERROR]\n", false, EXIT_FAILURE);
	engine->sems = sems;
	engine->philos = philos;
	engine->proc_ids = proc_ids;
	engine->philo_count = count;
	while (++i < count)
	{
		proc_ids[i] = -1;
		philos[i] = NULL;
	}
	init_sems(engine, sems, count);
	return (engine);
}
