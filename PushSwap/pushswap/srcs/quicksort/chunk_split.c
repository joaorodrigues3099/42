/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 07:28:15 by joao-alm          #+#    #+#             */
/*   Updated: 2024/12/09 07:28:15 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "quicksort.h"

void	ft_set_split(const t_loc *loc, t_split *split)
{
	if (*loc == A_TOP)
	{
		split->min.loc = B_BOT;
		split->med.loc = B_TOP;
		split->max.loc = A_BOT;
	}
	if (*loc == A_BOT)
	{
		split->min.loc = B_BOT;
		split->med.loc = B_TOP;
		split->max.loc = A_TOP;
	}
	if (*loc == B_TOP)
	{
		split->min.loc = B_BOT;
		split->med.loc = A_BOT;
		split->max.loc = A_TOP;
	}
	if (*loc == B_BOT)
	{
		split->min.loc = B_TOP;
		split->med.loc = A_BOT;
		split->max.loc = A_TOP;
	}
}

void	ft_init_sizes(t_split *split)
{
	split->max.size = 0;
	split->med.size = 0;
	split->min.size = 0;
}

void	ft_chunk_split(t_ps *pushswap, t_chunk *src, t_split *dest)
{
	int	*pivots;
	int	curr_value;

	pivots = (int *)malloc(2 * sizeof(int));
	if (!pivots)
		return ;
	ft_get_pivots(pivots, pushswap, src);
	ft_set_split(&src->loc, dest);
	ft_init_sizes(dest);
	while (src->size > 0)
	{
		curr_value = ft_chunk_value(pushswap, src, 0);
		if (curr_value >= pivots[1])
			dest->max.size += move_from_to(pushswap, src->loc, dest->max.loc);
		else if (curr_value >= pivots[0])
			dest->med.size += move_from_to(pushswap, src->loc, dest->med.loc);
		else
			dest->min.size += move_from_to(pushswap, src->loc, dest->min.loc);
		src->size--;
	}
	free (pivots);
}
