/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:55:01 by joao-alm          #+#    #+#             */
/*   Updated: 2025/02/14 13:42:52 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "philo_bonus.h"
#include "util.h"

static int	ft_handle_arg(int ac, char **av)
{
	int		i;
	long	param;

	if (ac < 5 || ac > 6)
		ft_exit(E_FORMAT, NULL);
	i = 0;
	while (++i < ac)
	{
		param = ft_atoi_v(av[i]);
		if (i == 1 && (param < 1 || param > 200))
			ft_exit(E_PHILO, NULL);
		if (i == 5 && (param < 0 || param > INT_MAX))
			ft_exit(E_MEALS, NULL);
		if (i != 1 && i != 5 && (param < 1 || param > INT_MAX))
			ft_exit(E_TIMES, NULL);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	ft_handle_arg(ac, av);
	ft_init(ac, av, &data);
	ft_exit(0, &data);
	return (0);
}
