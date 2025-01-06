/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:21:18 by joao-alm          #+#    #+#             */
/*   Updated: 2024/07/25 10:56:10 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*buffer;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	buffer = (int *)malloc(sizeof(int) * (max - min) + 1);
	if (!buffer)
		return (-1);
	i = 0;
	while (min < max)
		buffer[i++] = min++;
	*range = buffer;
	return (i);
}
/*
int	main(int argc, char **argv)
{
	int	min;
	int	max;
	int	*range;
	int	bound;

	if (argc == 3)
	{
		min = atoi(argv[1]);
		max = atoi(argv[2]);
	}
	bound = ft_ultimate_range(&range, min, max);
	printf("min = %d\nmax = %d\nbound = %d\n", min, max, bound);
}
*/