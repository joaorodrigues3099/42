/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:24:55 by abelayad          #+#    #+#             */
/*   Updated: 2023/05/30 19:44:43 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_break_while(t_args *args, int *i)
{
	pthread_mutex_lock(&args->sync_mutex);
	if (ft_now_ms() - args->philos[*i].last_meal_beginning
		>= (unsigned long long)args->time2die
		|| args->total_finished == args->philo_count)
	{
		if (args->max_meals != -1 && args->total_finished == args->philo_count)
		{
			args->everybody_full = true;
			pthread_mutex_unlock(&args->philos[*i].l_fork);
			printf("Every philosopher has eaten %d times\n", args->max_meals);
		}
		else
		{
			args->death_occured = true;
			pthread_mutex_unlock(&args->philos[*i].l_fork);
			printf("%lu %d died\n",
				ft_now_ms() - args->start_time, args->philos[*i].nbr);
		}
		pthread_mutex_unlock(&args->sync_mutex);
		return (true);
	}
	if (*i + 1 == args->philo_count)
		*i = -1;
	pthread_mutex_unlock(&args->sync_mutex);
	return (false);
}

// philo_count time2die time2eat time2sleep [meals_count]
int	main(int argc, char **argv)
{
	t_args		args;
	int			i;

	memset(&args, 0, sizeof(t_args));
	if (argc < 5 || argc > 6
		|| !ft_initialize_args(&args, argv))
		return (1);
	ft_initialize_philos(&args);
	i = -1;
	while (++i < args.philo_count)
		pthread_create(&args.philos[i].thread, NULL, proutine, &args.philos[i]);
	i = -1;
	while (++i < args.philo_count && !ft_break_while(&args, &i))
		i = i + 0;
	i = -1;
	while (++i < args.philo_count)
		pthread_join(args.philos[i].thread, NULL);
	i = -1;
	while (++i < args.philo_count)
		pthread_detach(args.philos[i].thread);
	i = -1;
	while (++i < args.philo_count)
		pthread_mutex_destroy(&args.philos[i].l_fork);
	return (0);
}
