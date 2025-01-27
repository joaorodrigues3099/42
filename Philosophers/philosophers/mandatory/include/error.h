/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_codes.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:07:42 by joao-alm          #+#    #+#             */
/*   Updated: 2025/01/27 13:35:40 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define PINK "\033[38;2;231;133;190m"
# define RESET "\033[0m"

# define E_OK 0

# define E_INVALID_FORMAT 10
# define E_INVALID_FORMAT_MSG \
	"Format: ./philo <n_philos> <die_time> <eat_time> <sleep_time> [n_meals]\n"

# define E_MEMORY_ALLOCATION 12
# define E_MEMORY_ALLOCATION_MSG "Memory allocation failed\n"

# define E_FAILED_CREATE_THREAD 13
# define E_FAILED_CREATE_THREAD_MSG "Failed to create thread\n"

# define E_INVALID_PHILO 101
# define E_INVALID_PHILO_MSG "<n_philos> must be a value between 1 and 200\n"

# define E_INVALID_DIE 102
# define E_INVALID_DIE_MSG "<die_time> must be a value between 1 and INT_MAX\n"

# define E_INVALID_EAT 103
# define E_INVALID_EAT_MSG "<eat_time> must be a value between 1 and INT_MAX\n"

# define E_INVALID_SLEEP 104
# define E_INVALID_SLEEP_MSG "<sleep_time> must be a value between 1 and INT_MAX\n"

# define E_INVALID_MEALS 105
# define E_INVALID_MEALS_MSG "[n_meals] must be a value between 0 and INT_MAX\n"

int	ft_print_error(int err_code);

#endif // ERROR_H
