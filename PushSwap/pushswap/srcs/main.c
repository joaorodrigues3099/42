/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:42:15 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/16 13:28:33 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/test.h"
#include "../includes/operations.h"

void	test(int *tab, int size, t_list *lst_a, t_list *lst_b)
{
	lst_a = ft_tab_to_lst(tab, size);
	test_print_lsts(lst_a, lst_b);

	ft_pb(&lst_a, &lst_b);
	ft_pb(&lst_a, &lst_b);
	ft_pb(&lst_a, &lst_b);
	test_print_lsts(lst_a, lst_b);

	ft_ra(&lst_a, 1);
	test_print_lsts(lst_a, lst_b);

	ft_rb(&lst_b, 1);
	test_print_lsts(lst_a, lst_b);

	ft_rr(&lst_a, &lst_b);
	test_print_lsts(lst_a, lst_b);

	ft_rra(&lst_a, 1);
	test_print_lsts(lst_a, lst_b);

	ft_rrb(&lst_b, 1);
	test_print_lsts(lst_a, lst_b);

	ft_rrr(&lst_a, &lst_b);
	test_print_lsts(lst_a, lst_b);

	ft_pa(&lst_a, &lst_b);
	ft_pa(&lst_a, &lst_b);
	ft_pa(&lst_a, &lst_b);
	test_print_lsts(lst_a, lst_b);
}

int	main(int ac, char **av)
{
	int		*tab;
	int		size;
	t_list	*lst_a;
	t_list	*lst_b;
	t_range	*ranges;

	tab = ft_get_tab(ac, av, &size);
	if (!tab)
		return (ft_print_error(), 1);
	if (ft_tab_dups(tab, size))
		return (ft_print_error(), 1);
	if (ft_tab_sorted(tab, size))
		return (0);
	ranges = ft_get_ranges(tab, size);
	if (!ranges)
		return (NULL);
	lst_a = NULL;
	lst_b = NULL;
	test(tab, size, lst_a, lst_b);
	return (0);
}
