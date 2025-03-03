/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:57:43 by joao-alm          #+#    #+#             */
/*   Updated: 2025/02/24 13:57:46 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

/**
 * Locates the first occurrence of a character in a string.
 *
 * @param str The string to search.
 * @param c The character to find.
 * @return Pointer to the first occurrence of the character,
 * or NULL if not found.
 */
char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}

/**
 * Creates a new list element with the given content.
 *
 * @param content The content of the new element.
 * @return A pointer to the new list element.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*new_elem;

	new_elem = (t_list *)malloc(sizeof(t_list));
	if (!new_elem)
		return (NULL);
	new_elem->content = content;
	new_elem->next = NULL;
	return (new_elem);
}

/**
 * Adds a new element to the end of the list.
 *
 * @param lst Pointer to the list's head.
 * @param new The new element to add.
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst)
	{
		last = *lst;
		while (last && last->next)
			last = last->next;
		last->next = new;
	}
	else
		*lst = new;
}

/**
 * Deletes a specific node from the list, safely freeing its content.
 *
 * @param head Pointer to the list's head.
 * @param node The node to delete.
 * @param del Function to free the content of the node.
 */
void	ft_lstdel_safely(t_list **head, t_list *node, void (*del)(void *))
{
	t_list	*current;

	if (!head || !*head || !node)
		return ;
	if (node == *head)
	{
		*head = node->next;
		if (del)
			del(node->content);
		free(node);
		return ;
	}
	current = *head;
	while (current->next != node)
		current = current->next;
	current->next = node->next;
	if (del)
		del(node->content);
	free(node);
}

/**
 * Clears the entire list, freeing all elements and their content.
 *
 * @param lst Pointer to the list's head.
 * @param del Function to free the content of each node.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;

	if (!lst)
		return ;
	while (*lst)
	{
		current = *lst;
		if (del)
			del((*lst)->content);
		*lst = (*lst)->next;
		free(current);
	}
}
