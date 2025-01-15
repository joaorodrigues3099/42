/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:16:54 by joao-alm          #+#    #+#             */
/*   Updated: 2024/07/24 19:29:16 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
//#include <stdio.h>

int	ft_check(int i, int nb)
{
	if (i == 1)
		return (1);
	if (nb % i == 0)
		return (0);
	return (ft_check(i - 1, nb));
}

int	ft_is_prime(int nb)
{
	if (nb <= 1)
		return (0);
	return (ft_check(nb - 1, nb));
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}
/*
int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("nxt prime: %d\n", ft_find_next_prime(atoi(argv[1])));
	return (0);
}
*/