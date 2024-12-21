/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jr_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:11:42 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/25 21:38:28 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/listlib.h"
#include "../../includes/memlib.h"

/**
 * Copies a List.
 *
 * @param lst Node to start iterating from.
 * @param del Function used to delete the Node's content, if necessary.
 * @return Returns a copy of the given List.
 */
t_list	*ft_lstcpy(t_list *lst, int type, void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;

	new_lst = NULL;
	while (lst)
	{
		new_elem = ft_lstnew(ft_dup_data(lst->content, type));
		if (!new_elem)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_elem);
		lst = lst->next;
	}
	return (new_lst);
}