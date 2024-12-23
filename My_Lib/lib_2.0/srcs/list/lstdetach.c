/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdetach.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:20:33 by joao-alm          #+#    #+#             */
/*   Updated: 2024/12/17 11:20:33 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lib_list.h"

t_list	*ft_lstdetach(t_list **head, t_list *node)
{
	t_list	*prev;
	t_list	*current;

	prev = NULL;
	current = *head;
	while (current != node)
	{
		prev = current;
		current = current->next;
	}
	if (prev)
		prev->next = current->next;
	else
		*head = current->next;
	node->next = NULL;
	return (node);
}
