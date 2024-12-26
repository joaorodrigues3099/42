/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:37:21 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/18 14:37:21 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "quicksort.h"

void	ft_rotate(t_stack *src, t_stack *dest)
{
	ft_lstadd_back(&dest->lst, ft_lstdetach(&src->lst, src->lst));
	src->size -= 1;
	dest->size += 1;
}

void	ft_ra(t_ps *ps)
{
	if (ps->a_top.size < 1)
		ft_rotate(&ps->a_bot, &ps->a_bot);
	else
		ft_rotate(&ps->a_top, &ps->a_bot);
	ft_lstadd_back(&ps->ops, ft_lstnew("ra"));
}

void	ft_rb(t_ps *ps)
{
	if (ps->b_top.size < 1)
		ft_rotate(&ps->b_bot, &ps->b_bot);
	else
		ft_rotate(&ps->b_top, &ps->b_bot);
	ft_lstadd_back(&ps->ops, ft_lstnew("rb"));
}

void	ft_rr(t_ps *ps)
{
	ft_ra(ps);
	ft_rb(ps);
	ft_lstdelone(ft_lstlast(ps->ops), NULL);
	ft_lstdelone(ft_lstlast(ps->ops), NULL);
	ft_lstadd_back(&ps->ops, ft_lstnew("rr"));
}
