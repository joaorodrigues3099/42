/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 08:32:52 by joao-alm          #+#    #+#             */
/*   Updated: 2025/01/27 14:16:34 by joao-alm         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	int		exit_code;
	t_data	data;
	int		i;

	exit_code = ft_handle_arg(ac, av);
	if (exit_code)
		return (exit_code);
	return (0);
}
