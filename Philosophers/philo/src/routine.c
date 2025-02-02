/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:44:54 by joao-alm          #+#    #+#             */
/*   Updated: 2025/01/29 11:59:20 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "../include/error.h"
#include "../include/philosophers.h"

size_t	ft_time_ms()
{
	struct timeval	tv;
	size_t	seconds;
	size_t	microseconds;

	gettimeofday(&tv, NULL);
	seconds = tv.tv_sec;
	microseconds = tv.tv_usec;
	return (seconds * 1000 + microseconds / 1000);
}

int	ft_stop(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex);
	if (philo->data->death || philo->data->full == philo->data->n_philos)
	{
		pthread_mutex_unlock(&philo->left_fork);
		pthread_mutex_unlock(&philo->left_fork);
		pthread_mutex_unlock(&philo->data->mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->mutex);
	return (0);
}

int ft_print_status(const t_philo *philo, const char *msg, const char *color)
{
	printf("%lld %s%d%s %s%s%s", ft_time_ms() - philo->data->start_time, BOLD, philo->id, RESET, color, msg, RESET);
	return (1);
}

int	ft_take_forks(t_philo *philo)
{
	if (ft_stop(philo))
		return (0);
	pthread_mutex_lock(&philo->left_fork);
	if (ft_stop(philo))
		return (0);
	ft_print_status(philo, "has taken a fork\n", YELLOW);
	if (philo->data->n_philos == 1)
		usleep(philo->data->die_time * 1000 + 1000);
	if (ft_stop(philo))
		return (0);
	pthread_mutex_lock(philo->right_fork);
	if (ft_stop(philo))
		return (0);
	ft_print_status(philo, "has taken a fork\n", YELLOW);
	if (ft_stop(philo))
		return (0);
	return (1);
}

int	ft_eat(t_philo *philo)
{
	if (!ft_take_forks(philo))
		return (0);
	pthread_mutex_lock(&philo->data->mutex);
	philo->meals_eaten++;
	philo->last_meal = ft_time_ms();
	pthread_mutex_unlock(&philo->data->mutex);
	if (ft_stop(philo))
		return (0);
	ft_print_status(philo,"is eating\n", GREEN);
	usleep(philo->data->eat_time * 1000);
	if (ft_stop(philo))
		return (0);
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (1);
}

int	ft_stop(t_data *data)
{
	int	i;

	while (data->)
	{

	}
}

void	*ft_routine(void *ptr)
{
	t_philo	*philo;

	philo = ptr;
	if (!(philo->id & 1))
		usleep(100);
	while (1)
	{
		if (!ft_eat(philo))
			break ;
		if (ft_stop(philo))
			break ;
		ft_print_status(philo,"is sleeping\n", PINK);
		usleep(philo->data->sleep_time * 1000);
		if (ft_stop(philo))
			break ;
		ft_print_status(philo,"is thinking\n", PINK);
	}
	return (NULL);
}