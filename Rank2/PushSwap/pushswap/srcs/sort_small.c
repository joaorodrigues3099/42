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
#include "quicksort.h"

void	ft_sort_two(t_ps *pushswap)
{
	ft_sa(pushswap);
}

void	ft_sort_three(t_ps *pushswap)
{
	int	first;
	int	sec;
	int	third;

	first = ft_lstget_int(pushswap->a_top.lst);
	sec = ft_lstget_int(pushswap->a_top.lst->next);
	third = ft_lstget_int(pushswap->a_top.lst->next->next);
	if (first < sec && sec > third)
		ft_rra(pushswap);
	if (first > sec && first > third)
		ft_ra(pushswap);
	first = ft_lstget_int(pushswap->a_top.lst);
	sec = ft_lstget_int(pushswap->a_top.lst->next);
	if (first > sec)
		ft_sa(pushswap);
}

void	ft_sort_five(t_ps *pushswap)
{
	while (pushswap->a_top.size + pushswap->a_bot.size > 3)
	{
		if (ft_lstget_int(pushswap->a_top.lst) == 1 ||
			ft_lstget_int(pushswap->a_top.lst) == 2)
			ft_pb(pushswap);
		else
			ft_rra(pushswap);
	}
	if (pushswap->b_top.size == 2 &&
		ft_lstget_int(pushswap->b_top.lst) < ft_lstget_int(pushswap->b_top.lst->next))
		ft_sb(pushswap);
	ft_sort_three(pushswap);
	ft_pa(pushswap);
	if (pushswap->b_top.size > 0)
		ft_pa(pushswap);
}
