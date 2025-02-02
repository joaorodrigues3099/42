/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:20:15 by abelayad          #+#    #+#             */
/*   Updated: 2023/05/30 19:36:14 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h> // for memset
# include <stdint.h> // to store miliseconds
# include <stdbool.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo {
	int				nbr;
	uint64_t		last_meal_beginning;
	int				meals_count;
	pthread_t		thread;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	*r_fork;
	struct s_args	*args;
}	t_philo;

typedef struct s_args {
	int					philo_count;
	int					time2die;
	int					time2eat;
	int					time2sleep;
	int					max_meals;
	int					total_finished;
	bool				death_occured;
	bool				everybody_full;
	uint64_t			start_time;
	pthread_mutex_t		sync_mutex;
	struct s_philo		philos[200];
}	t_args;

enum e_fork
{
	LEFT,
	RIGHT
};

int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
int			ft_isdigit(int c);
bool		ft_isint(char *str);
uint64_t	ft_now_ms(void);
size_t		ft_strlen(const char *str);
void		ft_usleep(uint64_t milli);
bool		ft_initialize_args(t_args *args, char **argv);
void		ft_initialize_philos(t_args *args);
bool		ft_break_while(t_args *args, int *i);
bool		ft_write_status(t_philo *philo, char *msg);
bool		ft_should_stop(t_philo *philo);
bool		ft_get_forks(t_philo *philo);
bool		ft_sleep_think(t_philo *philo);
void		*proutine(void	*data);

#endif