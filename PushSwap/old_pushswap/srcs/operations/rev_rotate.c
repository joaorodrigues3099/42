/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:00:11 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/18 16:00:11 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/operations.h"
#include <unistd.h>

void	ft_rra(t_list **lst_a, int print)
{
	t_list	*pre_last;
	t_list	*last;

	if (!*lst_a || !(*lst_a)->next)
			return ;
	pre_last = *lst_a;
	while (pre_last->next && pre_last->next->next)
		pre_last = pre_last->next;
	last = pre_last->next;
	ft_lstadd_front(lst_a, last);
	pre_last->next = NULL;
	if (print)
		write (1, "rra\n", 4);
}

void	ft_rrb(t_list **lst_b, int print)
{
	t_list	*pre_last;
	t_list	*last;

	if (!*lst_b || !(*lst_b)->next)
		return ;
	pre_last = *lst_b;
	while (pre_last->next && pre_last->next->next)
		pre_last = pre_last->next;
	last = pre_last->next;
	ft_lstadd_front(lst_b, last);
	pre_last->next = NULL;
	if (print)
		write (1, "rrb\n", 4);
}

void	ft_rrr(t_list **lst_a, t_list **lst_b)
{
	ft_rra(lst_a, 0);
	ft_rrb(lst_b, 0);
	write(1, "rrr\n", 4);
}
