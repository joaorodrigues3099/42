/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:01:30 by joao-alm          #+#    #+#             */
/*   Updated: 2025/01/27 13:35:40 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

#include <stdlib.h>

#include "philosophers.h"
#include <unistd.h>

static void	ft_puterr(const char *error)
{
	write(2, "Error\n", 6);
	write(2, PINK, ft_strlen(PINK));
	write(2, error, ft_strlen(error));
	write(2, RESET, ft_strlen(RESET));
}

int	ft_print_error(const int err_code)
{
	if (err_code == E_OK)
		return (0);
	if (err_code == E_INVALID_FORMAT)
		ft_puterr(E_INVALID_FORMAT_MSG);
	else if (err_code == E_MEMORY_ALLOCATION)
		ft_puterr(E_MEMORY_ALLOCATION_MSG);
	else if (err_code == E_FAILED_CREATE_THREAD)
		ft_puterr(E_FAILED_CREATE_THREAD_MSG);
	else if (err_code == E_FAILED_JOIN_THREAD)
		ft_puterr(E_FAILED_JOIN_THREAD_MSG);
	else if (err_code == E_INVALID_PHILO)
		ft_puterr(E_INVALID_PHILO_MSG);
	else if (err_code == E_INVALID_DIE)
		ft_puterr(E_INVALID_DIE_MSG);
	else if (err_code == E_INVALID_EAT)
		ft_puterr(E_INVALID_EAT_MSG);
	else if (err_code == E_INVALID_SLEEP)
		ft_puterr(E_INVALID_SLEEP_MSG);
	else if (err_code == E_INVALID_MEALS)
		ft_puterr(E_INVALID_MEALS_MSG);
	return (err_code);
}

int	ft_free_return(const t_data *data, const int err_code)
{
	free(data->philo);
	return (ft_print_error(err_code));
}
