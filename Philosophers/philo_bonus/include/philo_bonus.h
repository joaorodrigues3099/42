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
#define PHILO_BONUS_H

#include <stdlib.h>
#include <semaphore.h>

typedef struct s_semaphore
{
	sem_t	*sem;
	char	*name;
}				t_sem;

typedef struct	s_philo
{
	int				id;
	int				pid;
	size_t			last_meal;
	int				meal_count;
	pthread_mutex_t	eat;
	struct s_data	*data;

}				t_philo;

typedef struct s_data
{
	int		philo_count;
	t_philo	*philo;
	t_sem	forks;
	t_sem	monitor;
	t_sem	print;
	size_t	die_time;
	size_t	eat_time;
	size_t	sleep_time;
	int		n_meals;
	size_t	start_time;
	t_sem	stop;
}				t_data;

// routine
void	ft_routine(t_philo *philo);

// util
size_t	ft_time_ms(void);
long	ft_atoi_v(const char *str);
void	ft_init(int ac, char **av, t_data *data);

#endif //PHILO_BONUS_H
