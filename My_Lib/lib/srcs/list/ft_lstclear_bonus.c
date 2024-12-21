/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:11:11 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/26 19:11:11 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

/**
 * Clears all the List, starting from the given head address,
 * using the given del function to clear the contents of the nodes
 * and frees them afterward.
 *
 * @param lst Address to List's head
 * @param del Function to delete node's content.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		current = *lst;
		del((*lst)->content);
		*lst = (*lst)->next;
		free(current);
	}
}
