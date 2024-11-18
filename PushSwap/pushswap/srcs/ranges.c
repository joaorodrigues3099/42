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

t_range *ft_fill_quartiles(t_range	*ranges, int *tab, int size)
{
	ranges[0].min = INT_MIN;
	ranges[0].max = tab[size / 4];
	ranges[1].min = tab[size / 4];
	ranges[1].max = tab[size / 2];
	ranges[2].min = tab[size / 2];
	ranges[2].max = tab[3 * (size / 4)];
	ranges[3].min = tab[3 * (size / 4)];
	ranges[3].max = INT_MAX;
	return (ranges);
}

t_range	*ft_get_quartiles(int *tab, int size)
{
	int		*sorted_tab;
	int		i;
	t_range	*ranges;

	ranges = (t_range *)malloc(4 * sizeof(t_range));
	if (!ranges)
		return (NULL);
	sorted_tab = (int *)malloc(size * sizeof(int));
	if (!sorted_tab)
		return (free(ranges), NULL);
	i = -1;
	while (++i < size)
		sorted_tab[i] = tab[i];
	ft_sort_tab(sorted_tab, size);
	return (ft_fill_quartiles(ranges, tab, size));
}

