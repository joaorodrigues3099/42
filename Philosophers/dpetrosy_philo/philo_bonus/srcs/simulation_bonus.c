/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:37:57 by dapetros          #+#    #+#             */
/*   Updated: 2024/03/16 18:37:59 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

void	*die_checker(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (true)
	{
		sem_wait(philo->sems->die_sem);
		if (get_current_time() - philo->times.last_meal > philo->times.die)
		{
			print_action(philo, RED"died"RESET);
			sem_wait(philo->sems->write_sem);
			sem_post(philo->sems->meal_sem);
			exit(EXIT_SUCCESS);
		}
		sem_post(philo->sems->die_sem);
	}
	return (NULL);
}

void	*meal_checker(void *ptr)
{
	t_engine	*engine;
	int			finished;

	finished = 0;
	engine = (t_engine *)ptr;
	while (true)
	{
		sem_wait(engine->sems->meal_sem);
		++finished;
		if (finished >= engine->philo_count)
			destroy_all(engine, NULL, true, EXIT_SUCCESS);
	}
	return (NULL);
}

void	philo_routine(t_philo *philo)
{
	sem_wait(philo->sems->fork_sem);
	print_action(philo, "has taken a fork");
	sem_wait(philo->sems->fork_sem);
	print_action(philo, "has taken a fork");
	print_action(philo, "is eating");
	sem_wait(philo->sems->die_sem);
	philo->times.last_meal = get_current_time();
	philo->meals_eaten += 1;
	sem_post(philo->sems->die_sem);
	if (philo->meals_eaten >= philo->must_eat)
		sem_post(philo->sems->meal_sem);
	ft_usleep(philo->times.eat);
	sem_post(philo->sems->fork_sem);
	sem_post(philo->sems->fork_sem);
	print_action(philo, "is sleeping");
	ft_usleep(philo->times.sleep);
	print_action(philo, "is thinking");
}

void	start_simulation(t_engine *engine, int index)
{
	t_id	die_checker_id;
	t_philo	*philo;

	philo = engine->philos[index];
	if (pthread_create(&die_checker_id, NULL, die_checker, philo) != 0
		|| pthread_detach(die_checker_id) != 0)
		destroy_all(engine, "[Thread ERROR]\n", false, EXIT_FAILURE);
	philo->times.born_time = get_current_time();
	philo->times.last_meal = get_current_time();
	while (true)
		philo_routine(philo);
}

void	launcher(t_engine *engine, int count)
{
	t_id	meal_checker_id;
	t_philo	**philos;
	pid_t	id;
	int		i;

	i = -1;
	philos = engine->philos;
	if (philos[0]->must_eat > 0)
	{
		if (pthread_create(&meal_checker_id, NULL, meal_checker, engine) != 0)
			destroy_all(engine, "[Thread Open ERROR]\n", true, 1);
		if (pthread_detach(meal_checker_id) != 0)
			destroy_all(engine, "[Thread Detach ERROR]\n", true, 1);
	}
	while (++i < count)
	{
		id = fork();
		engine->proc_ids[i] = id;
		if (id == -1)
			destroy_all(engine, "[Fork ERROR]\n", true, 1);
		if (id == 0)
			start_simulation(engine, i);
	}
	waitpid(-1, NULL, 0);
}
