/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:26:16 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/14 18:40:47 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;

	if (min >= max)
		return (NULL);
	range = (int *)malloc(sizeof(int) * (max - min));
	if (!range)
		return (NULL);
	i = 0;
	while (min < max)
		range[i++] = min++;
	return (range);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	int	*range;
	int	lenght;
	int	i;

	if (ac != 3)
		return (1);
	range = ft_range(atoi(av[1]), atoi(av[2]));
	if (!range)
		return (1);
	lenght = atoi(av[2]) - atoi(av[1]);
	i = 0;
	while (i < lenght)
		printf("%d\n", range[i++]);
	return (0);
}
*/