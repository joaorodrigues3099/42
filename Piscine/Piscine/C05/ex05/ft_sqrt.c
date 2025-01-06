/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:01:32 by joao-alm          #+#    #+#             */
/*   Updated: 2024/07/24 19:37:33 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i * i < nb && i < nb / 2)
		i++;
	if (i * i == nb)
		return (i);
	return (0);
}
/*
int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("square root: %d\n", ft_sqrt(1));
	return (0);
}
*/