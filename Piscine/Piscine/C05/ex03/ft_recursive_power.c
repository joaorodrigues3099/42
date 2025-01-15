/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:20:06 by joao-alm          #+#    #+#             */
/*   Updated: 2024/07/24 17:14:50 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>

int	ft_recursive_power(int nb, int power)
{
	if ((nb == 0 && power == 0) || power == 0)
		return (1);
	if (power < 0)
		return (0);
	return (nb * ft_recursive_power(nb, power - 1));
}
/*
int	main(int argc, char **argv)
{
	if (argc == 3)
		printf("result: %d\n", \
		ft_recursive_power(atoi(argv[1]), atoi(argv[2])));
	return (0);
}
*/