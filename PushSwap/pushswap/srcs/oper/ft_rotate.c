/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <support@toujoustudios.net>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:34:03 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/09 18:34:03 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/ft_linklist.h"
#include "../../libft/includes/ft_memlib.h"
#include "../../includes/ft_stacks.h"
#include <stdlib.h>

void	ft_r(t_list **list)
{
	t_list	*next_node;

	if (!list || !(*list) || !(*list)->next)
		return ;
	next_node = (*list)->next;
	ft_lstadd_back(list, ft_lstnew((*list)->content));
	free(*list);
	*list = next_node;
}

void	ft_rr(t_list **l1, t_list **l2)
{
	ft_r(l1);
	ft_r(l2);
}

void	ft_revr(t_list **list)
{
	t_list	*last_node;

	if (!list || !(*list) || !(*list)->next)
		return ;
	last_node = ft_lstlast(*list);
	ft_lstadd_front(list, ft_lstnew(last_node->content));
	free(last_node);
}

void	ft_rrr(t_list **l1, t_list **l2)
{
	ft_revr(l1);
	ft_revr(l2);
}
