/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:41:25 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/26 16:53:21 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libft/includes/listlib.h"

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

//chuncks
int			**ft_get_chunks(int *tab, int size, int n_chuncks);

//utils
void		ft_print_error(void);
int			ft_lstget_int(t_list *lst);

//checks
int			ft_tab_sorted(int *tab, int size);
int			ft_tab_dups(int *tab, int size);

//tab_to_list
t_list		*ft_tab_to_lst(int *tab, int size);

//list_utils
void		ft_del(void *ptr);
t_list		*ft_lstnew_int(int i);
int			ft_lst_sorted(t_list *lst);

#endif //PUSH_SWAP_H
