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

#include "quicksort.h"

typedef struct s_pos
{
	int	first;
	int	second;
	int	third;
}	t_pos;

void	sort_three_top_a(t_ps *pushswap, t_chunk *to_sort, const t_pos *pos)
{
	if (pos->first > pos->second && pos->first > pos->third)
	{
		ft_sa(pushswap);
		ft_ra(pushswap);
		ft_sa(pushswap);
		ft_rra(pushswap);
	}
	else if (pos->second > pos->first && pos->second > pos->third)
	{
		ft_ra(pushswap);
		ft_sa(pushswap);
		ft_rra(pushswap);
	}
	to_sort->loc = A_TOP;
	to_sort->size -= 1;
	ft_chunk_sort_two(pushswap, to_sort);
}

void	sort_three_top_b(t_ps *pushswap, t_chunk *to_sort, const t_pos *pos)
{
	ft_pa(pushswap);
	if (pos->first > pos->second && pos->first > pos->third)
		ft_pa(pushswap);
	else if (pos->second > pos->first && pos->second > pos->third)
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

void	sort_three_bottom_a(t_ps *pushswap, t_chunk *to_sort, const t_pos *pos)
{
	ft_rra(pushswap);
	ft_rra(pushswap);
	if (pos->first > pos->second && pos->first > pos->third)
		ft_rra(pushswap);
	else if (pos->second > pos->first && pos->second > pos->third)
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

void	sort_three_bottom_b(t_ps *pushswap, t_chunk *to_sort, const t_pos *pos)
{
	ft_rrb(pushswap);
	ft_rrb(pushswap);
	if (pos->first > pos->second && pos->first > pos->third)
	{
		ft_sb(pushswap);
		ft_pa(pushswap);
		ft_rrb(pushswap);
	}
	else if (pos->second > pos->first && pos->second > pos->third)
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
	t_pos	pos;

	pos.first = ft_chunk_value(pushswap, to_sort, 0);
	pos.second = ft_chunk_value(pushswap, to_sort, 1);
	pos.third = ft_chunk_value(pushswap, to_sort, 2);
	if (to_sort->loc == A_TOP)
		sort_three_top_a(pushswap, to_sort, &pos);
	else if (to_sort->loc == A_BOT)
		sort_three_bottom_a(pushswap, to_sort, &pos);
	else if (to_sort->loc == B_TOP)
		sort_three_top_b(pushswap, to_sort, &pos);
	else if (to_sort->loc == B_BOT)
		sort_three_bottom_b(pushswap, to_sort, &pos);
}
