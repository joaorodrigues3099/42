/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:30:20 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/26 17:30:20 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linklist.h"

/**
 * Adds an Element to the beginning of the List and updates the List header.
 *
 * @param lst Address of the List head.
 * @param new New element to add to the Front of the List.
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}
