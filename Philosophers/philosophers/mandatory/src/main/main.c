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

#include <stdio.h>
#include "error.h"
#include "input.h"
#include "philosophers.h"

int	main(int ac, char **av)
{
	t_philo philo;
	t_data	data;

	if (ac < 5 || ac > 6)
		return (ft_print_error(E_INVALID_FORMAT));
	ft_get_input(&data, ac, av);

	return (0);
}
