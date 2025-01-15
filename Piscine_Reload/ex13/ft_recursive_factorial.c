/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:53:08 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/16 22:09:46 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial_recursive(int nb, int factorial)
{
	if (nb > 0)
	{
		factorial *= nb--;
		return (ft_recursive_factorial_recursive(nb, factorial));
	}
	return (factorial);
}

int	ft_recursive_factorial(int nb)
{
	if (nb < 0 || nb > 12)
		return (0);
	return (ft_recursive_factorial_recursive(nb, 1));
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	printf("ft_recursive_factorial: %d\n", ft_recursive_factorial(atoi(av[1])));
	return (0);
}
*/