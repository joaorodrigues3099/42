/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdel_safely.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 21:37:52 by joao-alm          #+#    #+#             */
/*   Updated: 2024/12/18 21:37:52 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_list.h"

void	ft_lstdel_safely(t_list **head, t_list *node, void (*del)(void *))
{
	t_list	*current;

	if (node == *head)
	{
		*head = node->next;
		ft_lstdelone(node, del);
		return ;
	}
	current = *head;
	while (current->next != node)
		current = current->next;
	current->next = node->next;
	ft_lstdelone(node, del);
}
