/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:41:25 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/16 12:42:21 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include "../libft/includes/linklist.h"

typedef enum e_stack
{
	stack_a,
	stack_b
}			t_stack;

typedef struct s_range
{
	int	min;
	int	max;
}				t_range;

//tab
int			*ft_get_tab(int ac, char **av, int *size);

//quartiles
t_range	*ft_get_ranges(int *tab, int size);

//utils
void		ft_print_error(void);

//checks
int			ft_tab_sorted(int *tab, int size);
int			ft_tab_dups(int *tab, int size);

//tab_to_list
t_list		*ft_tab_to_lst(int *tab, int size);

//list_utils
void		ft_del(void *ptr);
t_list		*ft_lstnew_int(int i);

#endif //PUSH_SWAP_H
