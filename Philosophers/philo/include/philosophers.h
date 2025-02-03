/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:14:12 by joao-alm          #+#    #+#             */
/*   Updated: 2025/01/27 13:14:19 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <pthread.h>

typedef struct	s_philo
{
	pthread_t		thread;
	int				id;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
	int				meals_eaten;
	size_t			last_meal;
	struct s_data	*data;
}				t_philo;

typedef struct	s_time
{
	size_t		die;
	size_t		eat;
	size_t		sleep;
	size_t		start;
}				t_time;

typedef struct	s_data
{
	int				n_philos;
	t_philo			*philo;
	pthread_mutex_t	print;
	pthread_mutex_t	meal;
	pthread_mutex_t	stop_mutex;
	t_time 			times;
	int				n_meals;
	int				n_full;
	int				death;
}				t_data;

int				ft_init_data(t_data *data, int ac, char **av);

void			*ft_monitor(void *ptr);
void			*ft_routine(void *ptr);

long			ft_atoi_v(const char *str);

size_t			ft_time_ms();
void			ft_usleep(size_t mls);

#endif //PHILOSOPHERS_H
