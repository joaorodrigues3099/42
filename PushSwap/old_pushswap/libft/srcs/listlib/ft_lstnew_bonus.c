/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:14:04 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/26 17:14:04 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/listlib.h"
#include <stdlib.h>

/**
 * Creates a new List Element with the given content.
 *
 * @param content Content of the Node to create.
 * @return Returns a new Node of the list with the given content.
 */
t_list	*ft_lstnew(void	*content)
{
	t_list	*new_elem;

	new_elem = (t_list *)malloc(sizeof(t_list));
	if (!new_elem)
		return (NULL);
	new_elem->content = content;
	new_elem->next = NULL;
	return (new_elem);
}
