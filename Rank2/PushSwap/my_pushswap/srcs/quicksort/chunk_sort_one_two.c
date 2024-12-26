/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_one_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:51:17 by joao-alm          #+#    #+#             */
/*   Updated: 2024/12/18 20:51:17 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quicksort.h"

void	ft_chunk_sort_one(t_ps *pushswap, t_chunk *chunk)
{
	if (chunk->loc == A_BOT || chunk->loc == B_BOT || chunk->loc == B_TOP)
		move_from_to(pushswap, chunk->loc, A_TOP);
	chunk->size -= 1;
}

void	ft_chunk_sort_two(t_ps *ps, t_chunk *chunk)
{
	if (chunk->loc == A_BOT || chunk->loc == B_BOT || chunk->loc == B_TOP)
	{
		move_from_to(ps, chunk->loc, A_TOP);
		move_from_to(ps, chunk->loc, A_TOP);
	}
	if (ft_lstget_int(ps->a_top.lst) > ft_lstget_int(ps->a_top.lst->next)
		|| (ps->a_top.size == 1
			&& ft_lstget_int(ps->a_top.lst) > ft_lstget_int(ps->a_bot.lst)))
		ft_sa(ps);
	chunk->size -= 2;
}
