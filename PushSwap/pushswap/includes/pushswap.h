/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:55:12 by joao-alm          #+#    #+#             */
/*   Updated: 2024/12/03 19:55:12 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "lib_list.h"

// Input
t_list		*ft_get_input(char **av, const int ac, int *size);
int			ft_lst_sorted(const t_list *lst);

// Locations
typedef enum e_loc
{
	A_TOP,
	A_BOT,
	B_TOP,
	B_BOT
}			t_loc;

// Stack
typedef struct s_stack
{
	t_list	*lst;
	int		size;
}			t_stack;

// PushSwap
typedef struct s_pushswap
{
	t_stack	a_top;
	t_stack	a_bot;
	t_stack	b_top;
	t_stack	b_bot;
	t_list	*ops;
}			t_ps;

// PushSwap
void		ft_error(t_ps *data);
void		ft_init_pushswap(t_ps *ps, t_list *lst, int size);
void		ft_free_pushswap(t_ps *pushswap);

// Sort Small
void		ft_sort_two(t_ps *pushswap);
void		ft_sort_three(t_ps *pushswap);
void		ft_sort_five(t_ps *pushswap);

// Quicksort
void		ft_quicksort(t_ps *pushswap);

// Ops List
void		ft_clean_ops(t_list **ops);
void		ft_print_ops(const t_list *ops);

// Operations

// Push
void		ft_pa(t_ps *ps);
void		ft_pb(t_ps *ps);

// Swap
void		ft_sa(t_ps *ps);
void		ft_sb(t_ps *ps);
void		ft_ss(t_ps *ps);

// Rotate
void		ft_ra(t_ps *ps);
void		ft_rb(t_ps *ps);
void		ft_rr(t_ps *ps);

// Reverse Rotate
void		ft_rra(t_ps *ps);
void		ft_rrb(t_ps *ps);
void		ft_rrr(t_ps *ps);

#endif // PUSHSWAP_H
