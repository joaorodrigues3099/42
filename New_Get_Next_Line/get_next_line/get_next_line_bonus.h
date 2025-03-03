/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:29:20 by joao-alm          #+#    #+#             */
/*   Updated: 2025/02/24 11:29:29 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

/**
 * @def BUFFER_SIZE
 *
 * @brief Sets the buffer size for reading data.
 *
 * Defaults to 1069 bytes if not already defined.
 */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1069
# endif

/**
 * @struct s_list
 * @brief A node in a singly linked list.
 *
 * This structure represents an element in a linked list,
 * holding data and a pointer to the next node.
 */
typedef struct s_list
{
	void			*content; /**< Content of the node */
	struct s_list	*next; /**< Pointer to the next node */
}					t_list;

// get_next_line_utils
char				*ft_strchr(const char *str, int c);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdel_safely(t_list **head, t_list *node,
						void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));

// get_next_line
char				*get_next_line(int fd);

#endif // GET_NEXT_LINE_H
