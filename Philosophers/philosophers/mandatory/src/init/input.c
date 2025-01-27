/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:21:29 by joao-alm          #+#    #+#             */
/*   Updated: 2025/01/27 11:21:29 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include "error.h"
#include "input.h"
#include "notlibft.h"

void	ft_get_input(t_data *data, int ac, char **av)
{
	int	valid;

	data->n_philos = (int)ft_atoll_valid(av[1], 1, 200, &valid);
	if (!valid)
		exit (ft_print_error(E_INVALID_PHILO));
	data->die_time = ft_atoll_valid(av[2], 1, INT_MAX, &valid);
	if (!valid)
		exit (ft_print_error(E_INVALID_DIE));
	data->eat_time = ft_atoll_valid(av[3], 1, INT_MAX, &valid);
	if (!valid)
		exit (ft_print_error(E_INVALID_EAT));
	data->sleep_time = ft_atoll_valid(av[4], 1, INT_MAX, &valid);
	if (!valid)
		exit (ft_print_error(E_INVALID_SLEEP));
	if (ac == 6)
	{
		data->n_meals = (int)ft_atoll_valid(av[5], 0, INT_MAX, &valid);
		if (!valid)
			exit (ft_print_error(E_INVALID_MEALS));
	}
	else
		data->n_meals = -1;
}
