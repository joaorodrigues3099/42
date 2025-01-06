/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:00:11 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/18 16:00:11 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quicksort.h"
#include <stdlib.h>

void	ft_rev_rotate(t_stack *src, t_stack *dest)
{
	ft_lstadd_front(&dest->lst, ft_lstdetach(&src->lst, ft_lstlast(src->lst)));
	src->size -= 1;
	dest->size += 1;
}

void	ft_rra(t_ps *ps)
{
	if (ps->a_bot.size < 1)
		ft_rev_rotate(&ps->a_top, &ps->a_top);
	else
		ft_rev_rotate(&ps->a_bot, &ps->a_top);
	ft_lstadd_back(&ps->ops, ft_lstnew("rra"));
}

void	ft_rrb(t_ps *ps)
{
	if (ps->b_bot.size < 1)
		ft_rev_rotate(&ps->b_top, &ps->b_top);
	else
		ft_rev_rotate(&ps->b_bot, &ps->b_top);
	ft_lstadd_back(&ps->ops, ft_lstnew("rrb"));
}

void	ft_rrr(t_ps *ps)
{
	ft_rra(ps);
	ft_rrb(ps);
	ft_lstdel_safely(&ps->ops, ft_lstlast(ps->ops), NULL);
	ft_lstdel_safely(&ps->ops, ft_lstlast(ps->ops), NULL);
	ft_lstadd_back(&ps->ops, ft_lstnew("rrr"));
}
