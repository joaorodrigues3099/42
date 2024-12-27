/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:30:19 by joao-alm          #+#    #+#             */
/*   Updated: 2024/12/27 12:30:19 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "checker_bonus.h"
#include "lib_string.h"
#include "lib_write.h"
#include "pushswap.h"

void	ft_call_op(t_ps *data, const char *op)
{
	if (!ft_strncmp(op, "pa", 2))
		ft_pa(data);
	else if (!ft_strncmp(op, "pb", 2))
		ft_pb(data);
	else if (!ft_strncmp(op, "rra", 3))
		ft_rra(data);
	else if (!ft_strncmp(op, "rrb", 3))
		ft_rrb(data);
	else if (!ft_strncmp(op, "rrr", 3))
		ft_rrr(data);
	else if (!ft_strncmp(op, "ra", 2))
		ft_ra(data);
	else if (!ft_strncmp(op, "rb", 2))
		ft_rb(data);
	else if (!ft_strncmp(op, "rr", 2))
		ft_rr(data);
	else if (!ft_strncmp(op, "sa", 2))
		ft_sa(data);
	else if (!ft_strncmp(op, "sb", 2))
		ft_sb(data);
	else if (!ft_strncmp(op, "ss", 2))
		ft_ss(data);
	else
		ft_error(data);
}

void	ft_move_bot_a_to_top(t_ps *data)
{
	while (data->a_bot.lst)
	{
		ft_lstadd_back(&data->a_top.lst,
			ft_lstdetach(&data->a_bot.lst, data->a_bot.lst));
		data->a_bot.size -= 1;
		data->a_top.size += 1;
	}
}

int	ft_all_in_top_a(const t_ps *data)
{
	return (!data->a_bot.size && !data->b_top.size && !data->b_bot.size);
}
