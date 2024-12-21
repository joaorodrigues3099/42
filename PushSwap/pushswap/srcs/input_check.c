/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:50:06 by joao-alm          #+#    #+#             */
/*   Updated: 2024/12/05 16:50:06 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_lst_no_dups(t_list *lst)
{
	t_list	*current;
	t_list	*temp;

	current = lst;
	while (current)
	{
		temp = lst;
		while (temp != current)
		{
			if (ft_lstget_int(temp) == ft_lstget_int(current))
				return (0);
			temp = temp->next;
		}
		current = current->next;
	}
	return (1);
}

int	ft_lst_sorted(t_list *lst)
{
	while (lst->next)
	{
		if (ft_lstget_int(lst) > ft_lstget_int(lst->next))
			return (0);
		lst = lst->next;
	}
	return (1);
}
