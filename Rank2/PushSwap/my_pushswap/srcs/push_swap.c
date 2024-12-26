/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:13:02 by joao-alm          #+#    #+#             */
/*   Updated: 2024/12/26 20:11:06 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_write.h"
#include "pushswap.h"
#include <stdlib.h>
#include <unistd.h>

static void	ft_init_pushswap(t_ps *ps, t_list *lst, int size)
{
	ps->a_top = (t_stack){lst, size};
	ps->a_bot = (t_stack){NULL, 0};
	ps->b_top = (t_stack){NULL, 0};
	ps->b_bot = (t_stack){NULL, 0};
	ps->ops = NULL;
}

static void	ft_pushswap(t_ps *pushswap)
{
	if (pushswap->a_top.size == 2)
		ft_sort_two(pushswap);
	else if (pushswap->a_top.size == 3)
		ft_sort_three(pushswap);
	else if (pushswap->a_top.size <= 5)
		ft_sort_five(pushswap);
	else
		ft_quicksort(pushswap);
}

static void	ft_free_pushswap(t_ps *pushswap)
{
	ft_lstclear(&pushswap->a_top.lst, NULL);
	ft_lstclear(&pushswap->a_bot.lst, NULL);
	ft_lstclear(&pushswap->b_top.lst, NULL);
	ft_lstclear(&pushswap->b_bot.lst, NULL);
	ft_lstclear(&pushswap->ops, NULL);
}

int	main(const int ac, char **av)
{
	t_ps	pushswap;
	t_list	*lst;
	int		size;

	lst = NULL;
	size = 0;
	if (ac <= 1)
		return (ft_putendl_fd("Error", STDERR_FILENO), 1);
	ft_get_input(&lst, av, ac, &size);
	if (!lst || !ft_lst_no_dups(lst))
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		return (ft_lstclear(&lst, NULL), 1);
	}
	if (ft_lst_sorted(lst))
		return (ft_lstclear(&lst, NULL), 0);
	ft_init_pushswap(&pushswap, lst, size);
	ft_pushswap(&pushswap);
	ft_clean_ops(&pushswap.ops);
	ft_print_ops(pushswap.ops);
	ft_free_pushswap(&pushswap);
	return (0);
}
