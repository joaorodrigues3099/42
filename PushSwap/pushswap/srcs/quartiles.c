/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:24:06 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/16 18:24:06 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include "../includes/push_swap.h"
#include <stdlib.h>

#include "../libft/includes/memlib.h"

void	ft_sort_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	j = 0;
	while (j < size)
	{
		i = j + 1;
		while (i < size)
		{
			if (tab[j] > tab[i])
			{
				temp = tab[j];
				tab[j] = tab[i];
				tab[i] = temp;
			}
			i++;
		}
		j++;
	}
}

int	**ft_alloc_quartiles(int **quartiles)
{
	int	i;

	quartiles = (int **)malloc(4 * sizeof(int *));
	if (!quartiles)
		return (NULL);
	i = -1;
	while (++i < 4)
	{
		quartiles[i] = (int *)malloc(2 * sizeof(int));
		if (!quartiles[i])
			return (ft_free_matrix((void **)quartiles, i), NULL);
	}
	return (quartiles);
}

int	**ft_fill_quartiles(int **quartiles, int *tab, int size)
{
	quartiles[0][0] = INT_MIN;
	quartiles[0][1] = tab[size / 4];
	quartiles[1][0] = tab[size / 4];
	quartiles[1][1] = tab[size / 2];
	quartiles[2][0] = tab[size / 2];
	quartiles[2][1] = tab[3 * (size / 4)];
	quartiles[3][0] = tab[3 * (size / 4)];
	quartiles[3][1] = INT_MAX;
	return (quartiles);
}

int	**ft_get_quartiles(int *tab, int size)
{
	int	**quartiles;
	int	*sorted_tab;
	int	i;

	quartiles = NULL;
	sorted_tab = (int *)malloc(size * sizeof(int));
	if (!sorted_tab)
		return (NULL);
	quartiles = ft_alloc_quartiles(quartiles);
	if (!quartiles)
		return (NULL);
	i = -1;
	while (++i < size)
		sorted_tab[i] = tab[i];
	ft_sort_tab(sorted_tab, size);
	return (ft_fill_quartiles(quartiles, tab, size));
}

