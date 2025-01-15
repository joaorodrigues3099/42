/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:11:25 by joao-alm          #+#    #+#             */
/*   Updated: 2024/07/24 17:14:41 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>

int	ft_iterative_power(int nb, int power)
{
	int	i;

	i = nb;
	if (power < 0)
		return (0);
	if ((nb == 0 && power == 0) || power == 0)
		return (1);
	while (--power > 0)
	{
		nb *= i;
	}
	return (nb);
}
/*
int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("nb: %d\n", atoi(argv[1]));
		printf("power: %d\n", atoi(argv[2]));
		printf("result: %d\n", \
		ft_iterative_power(atoi(argv[1]), atoi(argv[2])));
	}
	return (0);
}
*/