/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 08:00:03 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/18 08:00:03 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/operations.h"
#include "../../includes/push_swap.h"
#include "../../includes/sort.h"

void	ft_sort_3(t_list **lst)
{
	int	first;
	int	second;
	int	third;

	if (ft_lst_sorted(*lst))
		return ;
	if (*lst && (*lst)->next && ft_lstsize(*lst) == 2)
		ft_sa(lst, 1);
	else if (*lst && (*lst)->next && (*lst)->next->next)
	{
		first = ft_lstget_int(*lst);
		second= ft_lstget_int((*lst)->next);
		third = ft_lstget_int((*lst)->next->next);
		if (first > second && first > third)
			ft_ra(lst, 1);
		else if (first < second && second > third)
			ft_rra(lst, 1);
		first = ft_lstget_int(*lst);
		second= ft_lstget_int((*lst)->next);
		if (first > second)
			ft_sa(lst, 1);
	}
}
