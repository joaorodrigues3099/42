/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <support@toujoustudios.net>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:48:35 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/09 16:48:35 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/ft_linklist.h"
#include "../../includes/ft_stacks.h"

void	ft_swap_content(void **ptr1, void **ptr2)
{
	void	*temp_content;

	temp_content = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp_content;
}

void	ft_s(t_list *list)
{
	if (!list || !list->next)
		return ;
	ft_swap_content(&(list->content), &((list->next)->content));
}

void	ft_ss(t_list *l1, t_list *l2)
{
	ft_s(l1);
	ft_s(l2);
}