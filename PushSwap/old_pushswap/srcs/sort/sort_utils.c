/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 08:20:16 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/23 08:20:16 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "../../includes/sort.h"
#include "../../includes/push_swap.h"

int	ft_node_in_range(t_list *node, int *range)
{
	return (ft_lstget_int(node) >= range[0] && ft_lstget_int(node) <= range[1]);
}

int	ft_lst_in_range(t_list *lst, int *range)
{
	while (lst)
	{
		if (ft_node_in_range(lst, range))
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	ft_max(t_list *lst)
{
	int	max;

	max = INT_MIN;
	while (lst)
	{
		if (ft_lstget_int(lst) > max)
			max = ft_lstget_int(lst);
		lst = lst->next;
	}
	return (max);
}

int	ft_min(t_list *lst)
{
	int	min;

	min = INT_MAX;
	while (lst)
	{
		if (ft_lstget_int(lst) < min)
			min = ft_lstget_int(lst);
		lst = lst->next;
	}
	return (min);
}

int	ft_get_value(t_list *lst, int pos)
{
	if (pos < 0)
		pos = ft_lstsize(lst) + pos;
	while (lst && lst->next && pos--)
		lst = lst->next;
	return (ft_lstget_int(lst));
}