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

# include "philosophers.h"
# include <unistd.h>

// # define PINK	"\033[1m\033[38;2;231;133;190m"
// # define RESET	"\033[0m"
// # define YELLOW	"\033[1m\033[38;2;255;248;147m"
// # define GREEN	"\033[1m\033[38;2;129;223;164m"
// # define BOLD	"\033[1m"

# define PINK ""
# define RESET ""
# define YELLOW ""
# define GREEN ""
# define BOLD ""

enum		e_error_code
{
	E_FORMAT = 10,
	E_MEM_ALLOC = 12,
	E_CREATE_THREAD = 13,
	E_JOIN_THREAD = 14,
	E_PHILO = 100,
	E_TIMES = 101,
	E_MEALS = 102
};

int	ft_error(const int errno);

#endif // ERROR_H
