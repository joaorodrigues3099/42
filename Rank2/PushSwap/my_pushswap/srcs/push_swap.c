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

static void	ft_pushswap(const int ac, char **av)
{
	t_ps	pushswap;
	t_list	*lst;
	int		size;

	size = 0;
	lst = ft_get_input(av, ac, &size);
	ft_init_pushswap(&pushswap, lst, size);
	if (!lst)
		ft_error(&pushswap);
	if (!ft_lst_sorted(lst))
	{
		if (pushswap.a_top.size == 2)
			ft_sort_two(&pushswap);
		else if (pushswap.a_top.size == 3)
			ft_sort_three(&pushswap);
		else if (pushswap.a_top.size <= 5)
			ft_sort_five(&pushswap);
		else
			ft_quicksort(&pushswap);
		ft_clean_ops(&pushswap.ops);
		ft_print_ops(pushswap.ops);
	}
	ft_free_pushswap(&pushswap);
}

int	main(const int ac, char **av)
{
	if (ac <= 1)
		ft_error(NULL);
	ft_pushswap(ac, av);
	return (0);
}
