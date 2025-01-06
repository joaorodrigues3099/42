/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 21:58:03 by joao-alm          #+#    #+#             */
/*   Updated: 2024/07/14 11:13:10 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
*/
void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	swap;
	int	j;
	int	k;

	k = size - 1;
	i = k;
	j = k;
	while (i >= 0)
	{
		while (j >= 0)
		{
			if (tab[i] > tab[j])
			{
				swap = tab[j];
				tab[j] = tab[i];
				tab[i] = swap;
			}
			j--;
		}
		j = k;
		i--;
	}
}
/*
int	main(void)
{
	int	i;
	int	size;
	int	x[5];

	size = 5;
	x[0] = 1;
	x[1] = 4;
	x[2] = 3;
	x[3] = 5;
	x[4] = 2;
	i = 0;
	ft_sort_int_tab(x, size);
	while (i < size)
	{
		ft_putchar(48 + x[i]);
		i++;
	}
	return (0);
}
*/
