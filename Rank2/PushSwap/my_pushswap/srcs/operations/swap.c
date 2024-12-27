/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:07:53 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/18 09:07:53 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "quicksort.h"

void	ft_swap(t_stack *src, t_stack *dest)
{
	if (src == dest)
		ft_lstadd_front(&dest->lst, ft_lstdetach(&dest->lst, dest->lst->next));
	else
	{
		ft_lstadd_front(&dest->lst, ft_lstdetach(&src->lst, src->lst));
		ft_lstadd_front(&src->lst, ft_lstdetach(&dest->lst, dest->lst->next));
	}
}

void	ft_sa(t_ps *ps)
{
	if (ps->a_top.size + ps->a_bot.size < 2)
		return ;
	if (ps->a_top.size < 1)
		ft_swap(&ps->a_bot, &ps->a_bot);
	else if (ps->a_top.size == 1)
		ft_swap(&ps->a_bot, &ps->a_top);
	else
		ft_swap(&ps->a_top, &ps->a_top);
	ft_lstadd_back(&ps->ops, ft_lstnew("sa"));
}

void	ft_sb(t_ps *ps)
{
	if (ps->b_top.size + ps->b_bot.size < 2)
		return ;
	if (ps->b_top.size < 1)
		ft_swap(&ps->b_bot, &ps->b_bot);
	else if (ps->b_top.size == 1)
		ft_swap(&ps->b_bot, &ps->b_top);
	else
		ft_swap(&ps->b_top, &ps->b_top);
	ft_lstadd_back(&ps->ops, ft_lstnew("sb"));
}

void	ft_ss(t_ps *ps)
{
	ft_sa(ps);
	ft_sb(ps);
	ft_lstdel_safely(&ps->ops, ft_lstlast(ps->ops), NULL);
	ft_lstdel_safely(&ps->ops, ft_lstlast(ps->ops), NULL);
	ft_lstadd_back(&ps->ops, ft_lstnew("ss"));
}
