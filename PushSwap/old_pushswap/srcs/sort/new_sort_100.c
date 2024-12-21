/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sort_100.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:11:34 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/25 16:11:34 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "../../includes/sort.h"
#include "../../includes/push_swap.h"
#include "../../includes/operations.h"
#include "../../includes/test.h"
#include <stdlib.h>
#include <unistd.h>

#include "../../libft/includes/memlib.h"
#include <stdio.h>

typedef struct s_moves
{
	int	*tab;
	int	size;
}			t_moves;

#define TOP 0
#define BOT 1

int	ft_closest_top(t_list *lst, int *chunck1, int *chunck2)
{
	int	pos;

	if (!lst || !lst->next)
		return (0);
	pos = 0;
	while (lst && (!ft_node_in_range(lst, chunck1) && !ft_node_in_range(lst, chunck2)) && ++pos)
		lst = lst->next;
	return (pos);

}

int	ft_closest_bot(t_list *lst, int size, int *chunck1, int *chunck2)
{
	int	pos;
	int	closest;

	if (!lst || !lst->next)
		return (0);
	pos = 0;
	closest = 0;
	while (lst)
	{
		if (ft_node_in_range(lst, chunck1) || ft_node_in_range(lst, chunck2))
			closest = size - pos;
		lst = lst->next;
		pos++;
	}
	return (-closest);
}

t_list	*ft_simulate_move(t_list *lst, int top_bot, int *chunck1, int *chunck2)
{
	t_list	*new_lst;
	t_list	*next;
	int		rotations;
	int		size;

	new_lst = ft_lstcpy(lst, 0, &free);
	if (!new_lst)
		return (NULL);
	size = ft_lstsize(lst);
	if (top_bot == TOP)
	{
		rotations = ft_closest_top(lst, chunck1, chunck2);
		while (rotations-- > 0)
			ft_ra(&new_lst, 0);
	}
	else
	{
		rotations = ft_closest_bot(lst, size, chunck1, chunck2);
		while (rotations++ < 0)
			ft_rra(&new_lst, 0);
	}
	next = new_lst->next;
 	ft_lstdelone(new_lst, &free);
	new_lst = next;
	return (new_lst);
}

int	ft_get_cost(int *tab, int size)
{
	int	cost;
	int	i;

	cost = 0;
	i = 0;
	while (i < size)
		cost += ft_abs(tab[i++]);
	return (cost);
}

int	ft_n_in_range(t_list *lst, int *chunck1, int *chunck2)
{
	int	count;

	count = 0;
	while (lst)
	{
		if (ft_node_in_range(lst, chunck1) || ft_node_in_range(lst, chunck2))
			count++;
		lst = lst->next;
	}
	return (count);
}

t_moves ft_recursive_moves(t_list *lst, int **chuncks, int *tab, int size, int *depth, int n_in_range)
{
	t_moves	result;
    t_moves	top_solution;
    t_moves	bot_solution;
    t_list 	*new_lst;
    int		*next_tab;

	result.tab = tab;
	result.size = size;
    if (*depth >= 10 || (!ft_lst_in_range(lst, chuncks[0]) && !ft_lst_in_range(lst, chuncks[1])))
    {
		if (size == n_in_range)
    		(*depth)++;
    	return (result);
    }
    next_tab = ft_calloc(size + 1, sizeof(int));
	ft_memcpy(next_tab, tab, size * sizeof(int));
	next_tab[size] = ft_closest_top(lst, chuncks[0], chuncks[1]);
    new_lst = ft_simulate_move(lst, TOP, chuncks[0], chuncks[1]);
	//test_print_lst("Top_lst", new_lst);
    top_solution = ft_recursive_moves(new_lst, chuncks, next_tab, size + 1, depth, n_in_range);
    ft_lstclear(&new_lst, free);
	next_tab = ft_calloc(size + 1, sizeof(int));
	ft_memcpy(next_tab, tab, size * sizeof(int));
	next_tab[size] = ft_closest_bot(lst, ft_lstsize(lst), chuncks[0], chuncks[1]);
	new_lst = ft_simulate_move(lst, BOT, chuncks[0], chuncks[1]);
	//test_print_lst("Bot_lst", new_lst);
	bot_solution = ft_recursive_moves(new_lst, chuncks, next_tab, size + 1, depth, n_in_range);
	ft_lstclear(&new_lst, free);
    if (ft_get_cost(top_solution.tab, top_solution.size) < ft_get_cost(bot_solution.tab, bot_solution.size))
    {
    	free(bot_solution.tab);
    	return (top_solution);
    }
	free(top_solution.tab);
	return (bot_solution);
}

void	ft_sort_100(t_list **lst_a, t_list **lst_b, int **chuncks)
{
	t_moves	moves;
	int		**mm_chuncks;
	int		*tab;
	int		i;

	mm_chuncks = (int **)malloc(2 * sizeof(int *));
	if (!mm_chuncks)
		return ;
	mm_chuncks[0] = chuncks[0];
	mm_chuncks[1] = chuncks[1];
	tab = (int *)malloc(sizeof(int));
	int depth = 0;
	int	n_in_range = ft_n_in_range(*lst_a, mm_chuncks[0], mm_chuncks[1]);
	moves = ft_recursive_moves(*lst_a, mm_chuncks, tab, 0, &depth, n_in_range);
	i = -1;
	while (++i < moves.size)
	{
		if (moves.tab[i] < 0)
			while (moves.tab[i]++ < 0)
				ft_rra(lst_a, 1);
		else
			while (moves.tab[i]-- > 0)
				ft_ra(lst_a, 1);
		ft_pb(lst_a, lst_b);
	}
}