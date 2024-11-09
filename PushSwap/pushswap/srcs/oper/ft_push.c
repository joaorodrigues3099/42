/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <support@toujoustudios.net>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:22:31 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/09 18:22:31 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/ft_linklist.h"
#include "../../includes/ft_stacks.h"

void	ft_p(t_list **l_dest, t_list *l_src)
{
	t_list	*new_node;

	if (!l_src)
		return ;
	new_node = ft_lstnew(l_src->content);
	ft_lstadd_front(l_dest, new_node);
}
