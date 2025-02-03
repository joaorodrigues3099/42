/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 08:32:52 by joao-alm          #+#    #+#             */
/*   Updated: 2025/02/03 21:07:27 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "error.h"
#include "philosophers.h"
#include <sys/time.h>

int	ft_handle_arg(int ac, char **av)
{
	int		i;
	long	param;

	if (ac < 5 || ac > 6)
		return (ft_error(E_FORMAT));
	i = 0;
	while (++i < ac)
	{
		param = ft_atoi_v(av[i]);
		if (i == 1 && (param < 1 || param > 200))
			return (ft_error(E_PHILO));
		if (i == 5 && (param < 0 || param > INT_MAX))
			return (ft_error(E_TIMES));
		if (i != 1 && i != 5 && (param < 1 || param > INT_MAX))
			return (ft_error(E_MEALS));
	}
	return (0);
}

int ft_start_routine(t_data *data)
{
	int i;

	i = -1;
	while (++i < data->n_philos)
		if (pthread_create(&data->philo[i].thread, NULL,
		   ft_routine, (void *)&data->philo[i]) != 0)
			return (-1);
	return (0);
}

int	ft_stop_routine(t_data *data)
{
	int i;

	i = -1;
	while (++i < data->n_philos)
		if (pthread_join(data->philo[i].thread, NULL) != 0)
			return (-1);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->meal);
	i = -1;
	while (++i < data->n_philos)
		pthread_mutex_destroy(&data->philo[i].left_fork);
	return (0);
}

int	main(int ac, char **av)
{
	int		exit_code;
	t_data	data;

	exit_code = ft_handle_arg(ac, av);
	if (exit_code)
		return (exit_code);
	exit_code = ft_init_data(&data, ac, av);
	if (exit_code)
		return (exit_code);
	exit_code = ft_start_routine(&data);
	if (exit_code)
		return (exit_code);
	exit_code = ft_stop_routine(&data);
	if (exit_code)
		return (exit_code);
	if (data.death)
		printf("%zu %d has died\n", ft_time_ms() - data.times.start, data.death);
	else
		printf ("Everyone is full\n");
	return (0);
}
