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

#include "../../includes/operations.h"
#include <unistd.h>

void	ft_ra(t_list **lst_a, int print)
{
	t_list	*last;
	t_list	*swap;

	if (!*lst_a || !(*lst_a)->next)
		return ;
	last = ft_lstlast(*lst_a);
	swap = *lst_a;
	*lst_a = (*lst_a)->next;
	last->next = swap;
	swap->next = NULL;
	if (print)
		write(1, "ra\n", 3);
}

void	ft_rb(t_list **lst_b, int print)
{
	t_list	*last;
	t_list	*swap;

	if (!*lst_b || !(*lst_b)->next)
		return ;
	last = ft_lstlast(*lst_b);
	swap = *lst_b;
	*lst_b = (*lst_b)->next;
	last->next = swap;
	swap->next = NULL;
	if (print)
		write(1, "rb\n", 3);
}

void	ft_rr(t_list **lst_a, t_list **lst_b)
{
	ft_ra(lst_a, 0);
	ft_rb(lst_b, 0);
	write(1, "rr\n", 3);
}