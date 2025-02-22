/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:35:00 by joao-alm          #+#    #+#             */
/*   Updated: 2025/02/07 18:30:51 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

// Colors
# define PINK "\033[1m\033[38;2;231;133;190m"
# define RESET "\033[0m"
# define YELLOW "\033[1m\033[38;2;255;248;147m"
# define GREEN "\033[1m\033[38;2;129;223;164m"
# define PURPLE "\033[1m\033[38;2;170;133;220m"
# define BOLD "\033[1m"

// Debug
// # define PINK ""
// # define RESET ""
// # define YELLOW ""
// # define GREEN ""
// # define PURPLE ""
// # define BOLD ""

// Error Codes
enum	e_error_code
{
	E_FORMAT = 10,
	E_MEM_ALLOC = 12,
	E_CREATE_THREAD = 13,
	E_JOIN_THREAD = 14,
	E_MUTEX_INIT = 15,
	E_PHILO = 100,
	E_TIMES = 101,
	E_MEALS = 102
};

int		ft_print_error(int errno);

#endif // UTIL_H
