/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:08:05 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/26 16:31:39 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include "../../includes/sort.h"
#include "../../includes/push_swap.h"
#include "../../includes/operations.h"

int	ft_closest_to_value_min(t_list *lst, int value)
{
	int	closest_min;
	int	current_value;

	closest_min = INT_MIN;
	while (lst)
	{
		current_value = ft_lstget_int(lst);
		if (current_value > closest_min && current_value < value)
			closest_min = current_value;
		lst = lst->next;
	}
	return (closest_min);
}

long	ft_closest_to_value_max(t_list *lst, int value)
{
	long	closest_max;
	int	current_value;

	closest_max = (long)INT_MAX + 1;
	while (lst)
	{
		current_value = ft_lstget_int(lst);
		if (current_value < closest_max && current_value > value)
			closest_max = current_value;
		lst = lst->next;
	}
	return (closest_max);
}

int	ft_get_position(t_list *lst, int value)
{
	int	pos;

	pos = 0;
	while (lst)
	{
		if (ft_lstget_int(lst) == value)
			break ;
		lst = lst->next;
		pos++;
	}
	return (pos);
}

void ft_rotate_to_position(t_list **lst, int pos)
{
	int size = ft_lstsize(*lst);

	if (pos > size / 2)
	{
		while (pos++ < size)
			ft_rra(lst, 1);
	}
	else
	{
		while (pos-- > 0)
			ft_ra(lst, 1);
	}
}

 void ft_push_a(t_list **lst_a, t_list **lst_b)
 {
	long closest_a;
	int pos;

	while (*lst_b)
	{
		closest_a = ft_closest_to_value_max(*lst_a, ft_lstget_int(*lst_b));

		if (closest_a == (long)INT_MAX + 1)
			pos = ft_get_position(*lst_a, ft_min(*lst_a));
		else
			pos = ft_get_position(*lst_a, closest_a);

		ft_rotate_to_position(lst_a, pos);
		ft_pa(lst_a, lst_b);
		if (closest_a == (long)INT_MAX + 1)
			ft_ra(lst_a, 1);
	}
}

//void ft_push_a(t_list **lst_a, t_list **lst_b)
//{
//	int	max;
//	int	min;
//	int	size;
//
//	while (*lst_b)
//	{
//		max = ft_get_position(*lst_b, ft_max(*lst_b));
//		min = ft_get_position(*lst_b, ft_min(*lst_b));
//		size = ft_lstsize(*lst_b);
//		if ((min < size / 2 && min < max) || (max < size / 2 && min < max) ||
//			(max < size / 2 && min < size / 2 && min < max) || size - min <  size - max)
//		{
//			ft_rotate_to_position(lst_b, min);
//			ft_pa(lst_a, lst_b);
//		}
//		else
//		{
//			ft_rotate_to_position(lst_b, max);
//			ft_pa(lst_a, lst_b);
//		}
//		if (ft_first_larger_second(*lst_a))
//			ft_rr(lst_a, lst_b);
//	}
//}

void	ft_sort_100(t_list **lst_a, t_list **lst_b, int **chunks, int n_chunks)
{
	int	j;

	j = n_chunks / 2 - 1;
	while (j >= 0)
	{
		while (ft_lst_in_range(*lst_a, chunks[j]) || ft_lst_in_range(*lst_a, chunks[n_chunks - j - 1]))
		{
			if (*lst_b && ft_node_in_range(*lst_b, chunks[j]) &&
				!ft_node_in_range(*lst_a, chunks[j]) && !ft_node_in_range(*lst_a, chunks[n_chunks - j - 1]))
				ft_rr(lst_a, lst_b);
			else if (*lst_b && ft_node_in_range(*lst_b, chunks[j]))
				ft_rb(lst_b, 1);
			while (!ft_node_in_range(*lst_a, chunks[j]) && !ft_node_in_range(*lst_a, chunks[n_chunks - j - 1]))
				ft_ra(lst_a, 1);
			ft_pb(lst_a, lst_b);
			//if (*lst_b && ft_node_in_range(*lst_b, chunks[j]))
			//	ft_rb(lst_b, 1);
		}
		if (*lst_b && ft_node_in_range(*lst_b, chunks[j]))
			ft_rb(lst_b, 1);
		j--;
	}
	ft_push_a(lst_a, lst_b);
	ft_rotate_to_position(lst_a, ft_get_position(*lst_a, ft_min(*lst_a)));
}