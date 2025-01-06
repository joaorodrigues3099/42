/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 18:37:16 by joao-alm          #+#    #+#             */
/*   Updated: 2024/07/14 11:11:06 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
*/
void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	swap;

	i = 0;
	while (i < (size / 2))
	{
		swap = tab[i];
		tab [i] = tab[size - 1 - i];
		tab [size - 1 - i] = swap;
		i++;
	}
}
/*	
int	main(void)
{
	int	size;
	int	count;
	int i[5] = {1,2,3,4,5};	
	
	size = 5;	
	ft_rev_int_tab(i, size);
	count = 0;
	while (count < size)
	{
		ft_putchar(48 + i[count]);
		count++;
	}
	return (0);
}
*/
