/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:46:48 by joao-alm          #+#    #+#             */
/*   Updated: 2024/12/16 15:42:57 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "quicksort.h"

void	sort_three_top_a(t_ps *pushswap, t_chunk *to_sort, const int *pos)
{
	if (pos[0] > pos[1] && pos[0] > pos[2])
	{
		ft_sa(pushswap);
		ft_ra(pushswap);
		ft_sa(pushswap);
		ft_rra(pushswap);
	}
	else if (pos[1] > pos[0] && pos[1] > pos[2])
	{
		ft_ra(pushswap);
		ft_sa(pushswap);
		ft_rra(pushswap);
	}
	to_sort->loc = A_TOP;
	to_sort->size -= 1;
	ft_chunk_sort_two(pushswap, to_sort);
}

void	sort_three_top_b(t_ps *pushswap, t_chunk *to_sort, const int *pos)
{
	ft_pa(pushswap);
	if (pos[0] > pos[1] && pos[0] > pos[2])
		ft_pa(pushswap);
	else if (pos[1] > pos[0] && pos[1] > pos[2])
	{
		ft_pa(pushswap);
		ft_sa(pushswap);
	}
	else
	{
		ft_sb(pushswap);
		ft_pa(pushswap);
		ft_sa(pushswap);
	}
	ft_pa(pushswap);
	to_sort->loc = A_TOP;
	to_sort->size -= 1;
	ft_chunk_sort_two(pushswap, to_sort);
}

void	sort_three_bottom_a(t_ps *pushswap, t_chunk *to_sort, const int *pos)
{
	ft_rra(pushswap);
	ft_rra(pushswap);
	if (pos[0] > pos[1] && pos[0] > pos[2])
		ft_rra(pushswap);
	else if (pos[1] > pos[0] && pos[1] > pos[2])
	{
		ft_sa(pushswap);
		ft_rra(pushswap);
	}
	else
	{
		ft_pb(pushswap);
		ft_rra(pushswap);
		ft_sa(pushswap);
		ft_pa(pushswap);
	}
	to_sort->loc = A_TOP;
	to_sort->size -= 1;
	ft_chunk_sort_two(pushswap, to_sort);
}

void	sort_three_bottom_b(t_ps *pushswap, t_chunk *to_sort, const int *pos)
{
	ft_rrb(pushswap);
	ft_rrb(pushswap);
	if (pos[0] > pos[1] && pos[0] > pos[2])
	{
		ft_sb(pushswap);
		ft_pa(pushswap);
		ft_rrb(pushswap);
	}
	else if (pos[1] > pos[0] && pos[1] > pos[2])
	{
		ft_pa(pushswap);
		ft_rrb(pushswap);
	}
	else
	{
		ft_rrb(pushswap);
		ft_pa(pushswap);
	}
	to_sort->loc = B_TOP;
	to_sort->size -= 1;
	ft_chunk_sort_two(pushswap, to_sort);
}

void	ft_chunk_sort_three(t_ps *pushswap, t_chunk *to_sort)
{
	int	*pos;

	pos = (int *)malloc(3 * sizeof(int));
	if (!pos)
		return ;
	pos[0] = ft_chunk_value(pushswap, to_sort, 0);
	pos[1] = ft_chunk_value(pushswap, to_sort, 1);
	pos[2] = ft_chunk_value(pushswap, to_sort, 2);
	if (to_sort->loc == A_TOP)
		sort_three_top_a(pushswap, to_sort, pos);
	else if (to_sort->loc == A_BOT)
		sort_three_bottom_a(pushswap, to_sort, pos);
	else if (to_sort->loc == B_TOP)
		sort_three_top_b(pushswap, to_sort, pos);
	else if (to_sort->loc == B_BOT)
		sort_three_bottom_b(pushswap, to_sort, pos);
	free(pos);
}
