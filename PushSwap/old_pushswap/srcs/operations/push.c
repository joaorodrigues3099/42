/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:43:51 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/18 13:43:51 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../../includes/operations.h"
#include <unistd.h>

#include "../../includes/push_swap.h"

void	ft_pa(t_list **lst_a, t_list **lst_b)
{
	t_list *temp;

	if (!*lst_b)
		return ;
	ft_lstadd_front(lst_a, ft_lstnew((*lst_b)->content));
	temp = (*lst_b)->next;
	ft_lstdelone(*lst_b, NULL);
	*lst_b = temp;
	write(1, "pa\n", 3);
}

void	ft_pb(t_list **lst_a, t_list **lst_b)
{
	t_list *temp;

	if (!*lst_a)
		return ;
	ft_lstadd_front(lst_b, ft_lstnew((*lst_a)->content));
	temp = (*lst_a)->next;
	ft_lstdelone(*lst_a, NULL);
	*lst_a = temp;
	write(1, "pb\n", 3);
}
