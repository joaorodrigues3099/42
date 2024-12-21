/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:08:58 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/18 09:08:58 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../libft/includes/listlib.h"
#include <stdlib.h>

t_list	*ft_tab_to_lst(int *tab, int size)
{
	t_list	*lst;
	int		i;

	lst = NULL;
	i = -1;
	while (++i < size)
		ft_lstadd_back(&lst, ft_lstnew_int(tab[i]));
	return (lst);
}
