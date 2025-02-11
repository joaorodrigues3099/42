/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_codes.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:07:42 by joao-alm          #+#    #+#             */
/*   Updated: 2025/02/04 16:43:26 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "philosophers.h"
# include <unistd.h>

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

#endif // ERROR_H
