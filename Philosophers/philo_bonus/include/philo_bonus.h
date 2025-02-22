/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:53:38 by joao-alm          #+#    #+#             */
/*   Updated: 2025/02/08 17:55:12 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdatomic.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/mman.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_philo
{
	int						id;
	int						pid;
	pthread_mutex_t			meal_mutex;
	int						meal_mutex_init;
	size_t					last_meal_time;
	int						meal_count;
	struct s_dinning_table	*dtable;
}							t_philo;

typedef struct s_dinning_table
{
	int						philo_count;
	t_philo					*philo;
	sem_t					*forks;
	sem_t					*print;
	sem_t					*full;
	int						break_full;
	size_t					die_time;
	size_t					eat_time;
	size_t					sleep_time;
	int						min_meals;
	sem_t					*stop;
	size_t					start_time;
}							t_dtable;

// init
void						ft_init(int ac, char **av, t_dtable *dtable);

// philo
void						ft_fork(t_dtable *dtable);
void						ft_philo(void *arg);

// util
size_t						ft_time_ms(size_t start_time);
long						ft_atoi_v(const char *str);

#endif // PHILO_BONUS_H
