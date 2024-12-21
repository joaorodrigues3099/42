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

int	**ft_alloc_chunks(int n_chunks)
{
	int	**quartiles;
	int	i;

	quartiles = (int **)malloc(n_chunks * sizeof(int *));
	if (!quartiles)
		return (NULL);
	i = 0;
	while (i < n_chunks)
	{
		quartiles[i] = (int *)malloc(2 * sizeof(int));
		if (!quartiles[i])
			ft_free_matrix((void **)quartiles, i);
		i++;
	}
	return (quartiles);
}

void	ft_fill_chunks(int **chunks, int n_chunks, int *tab, int size)
{
	int	i;

	chunks[0][0] = INT_MIN;
	i = 0;
	while (i < n_chunks - 1)
	{
		chunks[i][1] = tab[size * (i + 1) / n_chunks];
		i++;
		chunks[i][0] = tab[size * i / n_chunks];
	}
	chunks[n_chunks - 1][1] = INT_MAX;
}

int	**ft_get_chunks(int *tab, int size, int n_chunks)
{
	int		*sorted_tab;
	int		i;
	int		**chunks;

	sorted_tab = (int *)malloc(size * sizeof(int));
	if (!sorted_tab)
		return (NULL);
	i = -1;
	while (++i < size)
		sorted_tab[i] = tab[i];
	ft_sort_tab(sorted_tab, size);
	chunks = ft_alloc_chunks(n_chunks);
	if (!chunks)
		return (free(sorted_tab), NULL);
	ft_fill_chunks(chunks, n_chunks, sorted_tab, size);
	free(sorted_tab);
	return (chunks);
}

