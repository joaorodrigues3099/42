/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 07:12:24 by joao-alm          #+#    #+#             */
/*   Updated: 2024/12/16 19:46:35 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quicksort.h"
#include <stdlib.h>

void	ft_chunk_to_top(t_ps *pushswap, t_chunk *chunk)
{
	if (chunk->loc == A_BOT && pushswap->a_top.size
		+ pushswap->a_bot.size == chunk->size)
	{
		chunk->loc = A_TOP;
		pushswap->a_top.lst = pushswap->a_bot.lst;
		pushswap->a_top.size = pushswap->a_bot.size;
		pushswap->a_bot.lst = NULL;
		pushswap->a_bot.size = 0;
	}
	if (chunk->loc == B_BOT && pushswap->b_top.size
		+ pushswap->b_bot.size == chunk->size)
	{
		chunk->loc = B_TOP;
		pushswap->b_top.lst = pushswap->b_bot.lst;
		pushswap->b_top.size = pushswap->b_bot.size;
		pushswap->b_bot.lst = NULL;
		pushswap->b_bot.size = 0;
	}
}

void	ft_rec_quicksort(t_ps *pushswap, t_chunk *chunk)
{
	t_split	dest;

	ft_chunk_to_top(pushswap, chunk);
	if (chunk->size <= 3)
	{
		if (chunk->size == 1)
			ft_chunk_sort_one(pushswap, chunk);
		else if (chunk->size == 2)
			ft_chunk_sort_two(pushswap, chunk);
		else if (chunk->size == 3)
			ft_chunk_sort_three(pushswap, chunk);
		return ;
	}
	ft_chunk_split(pushswap, chunk, &dest);
	ft_rec_quicksort(pushswap, &dest.max);
	ft_rec_quicksort(pushswap, &dest.med);
	ft_rec_quicksort(pushswap, &dest.min);
}

void	ft_quicksort(t_ps *pushswap)
{
	t_chunk	begin;

	begin.loc = A_TOP;
	begin.size = pushswap->a_top.size;
	ft_rec_quicksort(pushswap, &begin);
}
