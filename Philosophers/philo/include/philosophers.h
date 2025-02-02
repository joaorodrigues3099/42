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
	pthread_t			thread;
	int					id;
	pthread_mutex_t		left_fork;
	pthread_mutex_t		*right_fork;
	int					meals_eaten;
	unsigned long long	last_meal;
	struct s_data		*data;
}				t_philo;

typedef struct	s_data
{
	t_philo				*philo;
	int					n_philos;
	size_t				die_time;
	size_t				eat_time;
	size_t				sleep_time;
	int					n_meals;
	pthread_mutex_t		mutex;
	size_t				start_time;
	int					death;
	int					full;
}				t_data;

void				*ft_routine(void *ptr);

int					ft_init_data(t_data *data, int ac, char **av);
long			ft_atoi_v(const char *str);

size_t				ft_time_ms();
size_t				ft_strlen(const char *s);

#endif //PHILOSOPHERS_H
