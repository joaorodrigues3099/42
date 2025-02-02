/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:01:30 by joao-alm          #+#    #+#             */
/*   Updated: 2025/02/02 13:32:57 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include <unistd.h>

static void	ft_puterror(const char *error)
{
	write(2, "Error\n", 6);
	write(2, PINK, 29);
	while (*error)
		write(2,error++, 1);
	write(2, RESET, 7);
}

static void	ft_standard_error(const int errno)
{
	if (errno == E_FORMAT)
		ft_puterror("Format: ./philo <n_philos> <die_time> <eat_time> "
					"<sleep_time> [n_meals]\n");
	else if (errno == E_MEM_ALLOC)
		ft_puterror("Memory allocation failed\n");
	else if (errno == E_CREATE_THREAD)
		ft_puterror("Failed to create thread\n");
	else if (errno == E_JOIN_THREAD)
		ft_puterror("Failed to join thread\n");
}

int	ft_error(const int errno)
{
	if (errno < 100)
		ft_print_standard_error(errno);
	else if (errno == E_PHILO)
		ft_puterror("<n_philos> must be a value between 1 and 200\n");
	else if (errno == E_TIMES)
		ft_puterror("<die_time>, <eat_time> and <sleep_time> must be a value "
				  "between 1 and INT_MAX\n");
	else if (errno == E_MEALS)
		ft_puterror("[n_meals] must be a value between 0 and INT_MAX\n");
	return (errno);
}

