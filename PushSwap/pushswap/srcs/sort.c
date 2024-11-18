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

#include "../includes/push_swap.h"

int	ft_is_in_range(t_list *node, t_range range)
{
	int	i;

	i = *(int *)node->content;
	return (i >= range.min && i <= range.max);
}

int	ft_next_in_range(t_list *lst, t_range range)
{
	int	pos;

	pos = 0;
	while (lst && !ft_is_in_range(lst, range) && pos++)
		lst = lst->next;
	return (pos);
}

