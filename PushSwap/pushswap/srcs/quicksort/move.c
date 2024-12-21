/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 08:45:51 by joao-alm          #+#    #+#             */
/*   Updated: 2024/12/16 19:22:41 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quicksort.h"
#include <stdlib.h>

#include "ft_printf.h"
#include "test.h"

void	move_from_A_TOP(t_ps *pushswap, const t_loc to)
{
	if (to == B_TOP)
		ft_pb(pushswap);
	else if (to == A_BOT)
		ft_ra(pushswap);
	else if (to == B_BOT)
	{
		ft_pb(pushswap);
		ft_rb(pushswap);
	}
}

void	move_from_B_TOP(t_ps *pushswap, const t_loc to)
{
	if (to == A_TOP)
		ft_pa(pushswap);
	else if (to == B_BOT)
		ft_rb(pushswap);
	else if (to == A_BOT)
	{
		ft_pa(pushswap);
		ft_ra(pushswap);
	}
}

void	move_from_A_BOT(t_ps *pushswap, const t_loc to)
{
	if (to == A_TOP)
		ft_rra(pushswap);
	else if (to == B_TOP)
	{
		ft_rra(pushswap);
		ft_pb(pushswap);
	}
	else if (to == B_BOT)
	{
		ft_rra(pushswap);
		ft_pb(pushswap);
		ft_rb(pushswap);
	}
}

void	move_from_B_BOT(t_ps *pushswap, const t_loc to)
{
	if (to == B_TOP)
		ft_rrb(pushswap);
	else if (to == A_TOP)
	{
		ft_rrb(pushswap);
		ft_pa(pushswap);
	}
	else if (to == A_BOT)
	{
		ft_rrb(pushswap);
		ft_pa(pushswap);
		ft_ra(pushswap);
	}
}

int	move_from_to(t_ps *pushswap, const t_loc from, const t_loc to)
{
	if (from == A_TOP)
		move_from_A_TOP(pushswap, to);
	else if (from == B_TOP)
		move_from_B_TOP(pushswap, to);
	else if (from == A_BOT)
		move_from_A_BOT(pushswap, to);
	else if (from == B_BOT)
		move_from_B_BOT(pushswap, to);
	// ft_printf("%s\n", (char *)ft_lstlast(pushswap->ops)->content);
	return (1);
}
