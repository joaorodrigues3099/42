/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:07:53 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/18 09:07:53 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/operations.h"
#include <unistd.h>

void	ft_sa(t_list **lst_a, int print)
{
	t_list	*swap;

	if (!*lst_a || !*(lst_a + 1))
		return ;
	swap = (*lst_a)->next;
	(*lst_a)->next = swap->next;
	swap->next = *lst_a;
	*lst_a = swap;
	if (print)
		write(1, "sa\n", 3);
}

void	ft_sb(t_list **lst_b, int print)
{
	t_list	*swap;

	if (!*lst_b || !*(lst_b + 1))
		return ;
	swap = (*lst_b)->next;
	(*lst_b)->next = swap->next;
	swap->next = *lst_b;
	*lst_b = swap;
	if (print)
		write(1, "sb\n", 3);
}

void	ft_ss(t_list **lst_a, t_list **lst_b)
{
	ft_sa(lst_a, 0);
	ft_sb(lst_b, 0);
	write(1, "ss\n", 3);
}