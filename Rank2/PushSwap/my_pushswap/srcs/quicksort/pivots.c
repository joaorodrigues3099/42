/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivots.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:23:23 by joao-alm          #+#    #+#             */
/*   Updated: 2024/12/26 15:23:23 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/quicksort.h"
#include "../../lib_2.0/includes/lib_memory.h"
#include <stdlib.h>

void	ft_chunk_to_tab(int *tab, const t_ps *pushswap,
		const t_chunk *chunk_data)
{
	t_list	*chunk;
	int		i;

	chunk = ft_get_chunk(*pushswap, chunk_data);
	i = 0;
	while (chunk && i < chunk_data->size)
	{
		tab[i++] = ft_lstget_int(chunk);
		chunk = chunk->next;
	}
}

void	ft_get_pivots(int *pivots, const t_ps *pushswap,
		const t_chunk *chunk_data)
{
	int	*tab;
	int	size;

	size = chunk_data->size;
	tab = (int *)malloc(size * sizeof(int));
	if (!tab)
		return ;
	ft_chunk_to_tab(tab, pushswap, chunk_data);
	ft_sort_tab(tab, size);
	if (size < 15)
	{
		pivots[0] = tab[0];
		pivots[1] = tab[size / 2];
	}
	else
	{
		pivots[0] = tab[size / 3];
		pivots[1] = tab[2 * size / 3];
	}
	free(tab);
}
