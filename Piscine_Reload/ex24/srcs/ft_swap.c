/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:01:03 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/14 12:11:25 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	a;
	int	b;

	if (ac != 3)
		return (1);
	a = atoi(av[1]);
	b = atoi(av[2]);
	printf("==> before <==\n");
	printf("a: %d\n", a);
	printf("b: %d\n", b);
	ft_swap(&a, &b);
	printf("==> after <==\n");
	printf("a: %d\n", a);
	printf("b: %d\n", b);
}
*/