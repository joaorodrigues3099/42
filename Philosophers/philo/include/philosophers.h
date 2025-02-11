/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:14:12 by joao-alm          #+#    #+#             */
/*   Updated: 2025/02/04 09:31:02 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				thread_init;
	int				id;
	pthread_mutex_t	left_fork;
	int				left_init;
	pthread_mutex_t	*right_fork;
	int				meals_eaten;
	size_t			last_meal;
	int				full;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	t_philo			*philo;
	int				n_philos;
	pthread_mutex_t	print;
	int				print_init;
	pthread_mutex_t	meal;
	int				meal_init;
	pthread_mutex_t	monitor;
	int				monitor_init;
	size_t			die_time;
	size_t			eat_time;
	size_t			sleep_time;
	size_t			start_time;
	int				n_meals;
	int				n_full;
	int				death;
}					t_data;

// init
int					ft_init_data(t_data *data, int ac, char **av);
// routine
int					ft_start_routine(t_data *data);
void				ft_monitor(t_data *data);
// routine_util
int					ft_stop_routine(t_philo *philo);
int					ft_print_status(t_philo *philo, const char *msg);
// util
size_t				ft_time_ms(void);
long				ft_atoi_v(const char *str);
// exit
int					ft_exit(t_data *data, int exit_code);

#endif // PHILOSOPHERS_H
