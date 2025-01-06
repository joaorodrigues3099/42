/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:30:13 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/14 15:20:58 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	sqrt;

	sqrt = 1;
	if (nb > 0)
	{
		while (sqrt <= nb / sqrt && sqrt <= 46340)
		{
			if (sqrt * sqrt == nb)
				return (sqrt);
			sqrt++;
		}
	}
	return (0);
}
/*
#includes <stdio.h>
#includes <stdlib.h>

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	printf("sqrt: %d\n", ft_sqrt(atoi(av[1])));
	return (0);
}
*/