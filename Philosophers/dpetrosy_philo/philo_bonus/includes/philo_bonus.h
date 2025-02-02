/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:39:41 by dapetros          #+#    #+#             */
/*   Updated: 2024/03/16 18:40:45 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>
# include <sys/types.h>
# include <semaphore.h>

# define RESET    "\033[0m"
# define RED      "\033[31m"    /* Red */
# define GREEN    "\033[32m"    /* Green */

# define DIE_SEM_NAME "/die_sem"
# define FORK_SEM_NAME "/fork_sem"
# define MEAL_SEM_NAME "/meal_sem"
# define WRITE_SEM_NAME "/write_sem"

# define PHILO_MAX_COUNT 200

typedef pthread_t		t_id;
typedef pthread_mutex_t	t_mutex;
typedef struct timeval	t_timeval;

typedef struct s_sems
{
	sem_t	*die_sem;
	sem_t	*fork_sem;
	sem_t	*meal_sem;
	sem_t	*write_sem;
}	t_sems;

typedef struct s_times
{
	size_t	die;
	size_t	eat;
	size_t	sleep;
	size_t	last_meal;
	size_t	born_time;
}	t_times;

typedef struct s_philo
{
	int			id;
	t_sems		*sems;
	t_times		times;
	int			must_eat;
	int			meals_eaten;
	int			philo_count;
}	t_philo;

typedef struct s_engine
{
	t_sems	*sems;
	t_philo	**philos;
	pid_t	*proc_ids;
	int		philo_count;
}	t_engine;

#endif   /* PHILO_BONUS_H */
