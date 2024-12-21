/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimal_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:26:27 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/21 13:26:27 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/operations.h"
#include "../../includes/push_swap.h"

int ft_first_larger_second(t_list *lst)
{
	int	first;
	int	second;

	if (!lst || !lst->next)
		return (0);
	first = ft_lstget_int(lst);
	second = ft_lstget_int(lst->next);
	return (first > second);
}

int	ft_first_larger_last(t_list *lst)
{
	int	first;
	int	last;

	if (!lst || !lst->next)
		return (0);
	first = ft_lstget_int(lst);
	last = ft_lstget_int(ft_lstlast(lst));
	return (first > last);
}

void	ft_best_swap(t_list **lst_a, t_list **lst_b)
{
	if (!ft_first_larger_second(*lst_b))
		ft_ss(lst_a, lst_b);
	else
		ft_sa(lst_a, 1);
}

void	ft_best_rotate(t_list **lst_a, t_list **lst_b)
{
	if (!ft_first_larger_second(*lst_b) && !ft_first_larger_last(*lst_b))
		ft_rr(lst_a, lst_b);
	else
		ft_ra(lst_a, 1);
}

void	ft_best_rev_rotate(t_list **lst_a, t_list **lst_b)
{
	if (!ft_first_larger_last(*lst_b))
		ft_rrr(lst_a, lst_b);
	else
		ft_rra(lst_a, 1);
}
