/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 08:32:52 by joao-alm          #+#    #+#             */
/*   Updated: 2025/02/05 16:58:50 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "philosophers.h"
#include <limits.h>

/**
 * Validates and handles command-line arguments.
 *
 * @param ac Argument count.
 * @param av Argument vector.
 * @return 0 on success, error code on failure.
 */
int	ft_handle_arg(int ac, char **av)
{
	int		i;
	long	param;

	if (ac < 5 || ac > 6)
		return (E_FORMAT);
	i = 0;
	while (++i < ac)
	{
		param = ft_atoi_v(av[i]);
		if (i == 1 && (param < 1 || param > 200))
			return (E_PHILO);
		if (i == 5 && (param < 0 || param > INT_MAX))
			return (E_MEALS);
		if (i != 1 && i != 5 && (param < 1 || param > INT_MAX))
			return (E_TIMES);
	}
	return (0);
}

/**
 * Entry point of the program.
 *
 * @param ac Argument count.
 * @param av Argument vector.
 * @return 0 on successful execution, error code on failure.
 */
int	main(int ac, char **av)
{
	int		exit_code;
	t_data	data;

	exit_code = ft_handle_arg(ac, av);
	if (exit_code)
		return (ft_print_error(exit_code));
	exit_code = ft_init_data(&data, ac, av);
	if (exit_code)
		return (ft_exit(&data, exit_code));
	exit_code = ft_start_routine(&data);
	if (exit_code)
		return (ft_exit(&data, exit_code));
	ft_monitor(&data);
	ft_exit(&data, 0);
	return (0);
}
