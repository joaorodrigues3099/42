/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:12:54 by joao-alm          #+#    #+#             */
/*   Updated: 2024/12/18 21:17:32 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <limits.h>
#include <stdlib.h>

void	ft_sort_two(t_ps *ps)
{
	ft_sa(ps);
}

void	ft_sort_three(t_ps *ps)
{
	int	first;
	int	sec;
	int	third;

	first = ft_lstget_int(ps->a_top.lst);
	sec = ft_lstget_int(ps->a_top.lst->next);
	third = ft_lstget_int(ps->a_top.lst->next->next);
	if (first < sec && sec > third)
		ft_rra(ps);
	if (first > sec && first > third)
		ft_ra(ps);
	first = ft_lstget_int(ps->a_top.lst);
	sec = ft_lstget_int(ps->a_top.lst->next);
	if (first > sec)
		ft_sa(ps);
}

void	ft_get_mins(int *mins, t_list *lst)
{
	t_list	*current;

	mins[0] = INT_MAX - 1;
	mins[1] = INT_MAX;
	current = lst;
	while (current)
	{
		if (ft_lstget_int(current) < mins[0])
			mins[0] = ft_lstget_int(current);
		current = current->next;
	}
	current = lst;
	while (current)
	{
		if (ft_lstget_int(current) < mins[1]
			&& ft_lstget_int(current) > mins[0])
			mins[1] = ft_lstget_int(current);
		current = current->next;
	}
}

void	ft_sort_five(t_ps *ps)
{
	int	*mins;
	int	og_size;

	mins = (int *)malloc(2 * sizeof(int));
	if (!mins)
		return ;
	ft_get_mins(mins, ps->a_top.lst);
	og_size = ps->a_top.size;
	while (ps->a_top.size + ps->a_bot.size > 3)
	{
		if (ft_lstget_int(ps->a_top.lst) == mins[0]
			|| (ft_lstget_int(ps->a_top.lst) == mins[1] && og_size == 5))
			ft_pb(ps);
		else
			ft_rra(ps);
	}
	if (ps->b_top.size == 2
		&& ft_lstget_int(ps->b_top.lst) < ft_lstget_int(ps->b_top.lst->next))
		ft_sb(ps);
	ft_sort_three(ps);
	ft_pa(ps);
	if (ps->b_top.size > 0)
		ft_pa(ps);
	free(mins);
}
