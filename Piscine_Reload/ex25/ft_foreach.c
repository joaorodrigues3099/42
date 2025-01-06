/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:39:47 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/14 19:45:43 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int lenght, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < lenght)
		(*f)(tab[i++]);
}
/*
#includes <stdio.h>
#includes <stdlib.h>

void	ft_print(int nb)
{
	printf("%d\n", nb);
}

int	main(int ac, char **av)
{
	int	*tab;
	int	i;

	if (ac < 2)
		return (1);
	i = 0;
	tab = malloc(sizeof(int) * (ac - 1));
	while (i++ < ac - 1)
		tab[i - 1] = atoi(av[i]);
	ft_foreach(tab, ac - 1, &ft_print);
	return (0);
}
*/