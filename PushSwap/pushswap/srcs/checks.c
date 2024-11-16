/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:18:43 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/16 19:18:43 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_tab_sorted(int *tab, int size)
{
	int	i;
	int	j;

	j = 0;
	while (j < size)
	{
		i = j + 1;
		while (i < size)
		{
			if (tab[j] > tab[i])
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	ft_tab_dups(int *tab, int size)
{
	int	i;
	int	j;

	j = 0;
	while (j < size)
	{
		i = j + 1;
		while (i < size)
		{
			if (tab[j] == tab[i])
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}
