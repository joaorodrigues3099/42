/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:47:48 by joao-alm          #+#    #+#             */
/*   Updated: 2024/12/02 17:47:48 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "quicksort.h"
#include "ft_printf.h"

void	test_print_lst(char *name, const t_stack *stack)
{
    t_list  *lst;

    lst = stack->lst;
    ft_printf("%s: ", name);
    while (lst)
    {
        ft_printf("%d -> ", ft_lstget_int(lst));
        lst = lst->next;
    }
    //ft_printf("NULL\n");
    ft_printf("size: %d\n", stack->size);
}

void	test_print_stacks(t_ps *pushswap)
{
    (void)pushswap;
    //
    // test_print_lst("A_TOP", &pushswap->a_top);
    // test_print_lst("A_BOT", &pushswap->a_bot);
    // test_print_lst("B_TOP", &pushswap->b_top);
    // test_print_lst("B_BOT", &pushswap->b_bot);
}
