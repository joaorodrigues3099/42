/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:12:09 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/14 12:16:47 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
#includes <stdio.h>
#includes <stdlib.h>

int	main(int ac, char **av)
{
	int	a;
	int	b;
	int	div;
	int	mod;

	if (ac != 3)
		return (1);
	a = atoi(av[1]);
	b = atoi(av[2]);
	ft_div_mod(a, b, &div, &mod);
	printf("a: %d\n", a);
	printf("b: %d\n", b);
	printf("div: %d\n", div);
	printf("mod: %d\n", mod);
	return (0);
}
*/