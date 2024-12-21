/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:13:02 by joao-alm          #+#    #+#             */
/*   Updated: 2024/12/04 17:46:21 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pushswap.h"
#include "lib_write.h"

static void ft_init_pushswap(t_ps *ps, t_list *lst, int size)
{
    ps->a_top = (t_stack){lst, size};
    ps->a_bot = (t_stack){NULL, 0};
    ps->b_top = (t_stack){NULL, 0};
    ps->b_bot = (t_stack){NULL, 0};
    ps->ops = NULL;
}

static void ft_pushswap(t_ps *pushswap)
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

int	main(const int ac, char **av)
{
    t_ps    pushswap;
    t_list  *lst;
    int     size;

    lst = NULL;
    size = 0;
    ft_get_input(&lst, av, ac, &size);
    if (!lst || size < 2 || !ft_lst_no_dups(lst))
    {
        ft_putendl_fd("Error", 2);
        return (1);
    }
    if (ft_lst_sorted(lst))
        return (0);
    ft_init_pushswap(&pushswap, lst, size);
    ft_pushswap(&pushswap);
    ft_clean_ops(&pushswap.ops);
    ft_print_ops(pushswap.ops);
    return (0);
}
