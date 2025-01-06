/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 08:16:15 by joao-alm          #+#    #+#             */
/*   Updated: 2024/07/25 10:20:38 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*buffer;
	int	i;

	if (min >= max)
		return (NULL);
	buffer = (int *)malloc(sizeof(int) * (max - min) + 1);
	i = 0;
	while (min < max)
		buffer[i++] = min++;
	return (buffer);
}
/*
int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 3)
	{
		while (i < (atoi(argv[2]) - atoi(argv[1])))
			printf("ft_range: %d\n", \
			ft_range(atoi(argv[1]), atoi(argv[2]))[i++]);
	}
	return (0);
}
*/