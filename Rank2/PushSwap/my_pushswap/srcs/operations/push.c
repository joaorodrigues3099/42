/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:43:51 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/18 13:43:51 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quicksort.h"

void	ft_push(t_stack *src, t_stack *dest)
{
	ft_lstadd_front(&dest->lst, ft_lstdetach(&src->lst, src->lst));
	src->size -= 1;
	dest->size += 1;
}

void	ft_pa(t_ps *ps)
{
	if (ps->b_top.size + ps->b_bot.size < 1)
		return ;
	if (ps->b_top.size < 1)
		ft_push(&ps->b_bot, &ps->a_top);
	else
		ft_push(&ps->b_top, &ps->a_top);
	ft_lstadd_back(&ps->ops, ft_lstnew("pa"));
}

void	ft_pb(t_ps *ps)
{
	if (ps->a_top.size + ps->a_bot.size < 1)
		return ;
	if (ps->a_top.size < 1)
		ft_push(&ps->a_bot, &ps->b_top);
	else
		ft_push(&ps->a_top, &ps->b_top);
	ft_lstadd_back(&ps->ops, ft_lstnew("pb"));
}
