/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:42:15 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/26 19:10:02 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/test.h"
#include "../includes/sort.h"
#include <stdlib.h>
#include <stdio.h>

void	test(int *tab, int size, t_list **lst_a, t_list **lst_b)
{
	int		**chunks;
	int		n_chunks;

	*lst_a = ft_tab_to_lst(tab, size);
	//test_print_lsts(*lst_a, *lst_b);
	n_chunks = 6;
	chunks = ft_get_chunks(tab, size, n_chunks);
	//for (int i = 0; i < n_chunks; i++)
	//{
	//	printf("chunck[%d][0]: %d\n", i, chunks[i][0]);
	//	printf("chunck[%d][1]: %d\n", i, chunks[i][1]);
	//}
	ft_sort_100(lst_a, lst_b, chunks, n_chunks);
	//test_print_lsts(*lst_a, *lst_b);
}

int	main(int ac, char **av)
{
	int		*tab;
	int		size;
	t_list	*lst_a;
	t_list	*lst_b;

	tab = ft_get_tab(ac, av, &size);
	if (!tab)
		return (ft_print_error(), 1);
	if (ft_tab_dups(tab, size))
		return (free(tab), ft_print_error(), 1);
	if (ft_tab_sorted(tab, size))
		return (free(tab), 0);
	lst_a = NULL;
	lst_b = NULL;
	test(tab, size, &lst_a, &lst_b);
	return (0);
}

//199: 5 35 67 97 26 77 50 24 92 57 71 40 42 8 62 16 6 11 70 87 49 44 91 81 69 46 61 84 21 58 78 59 85 43 68 53 98 27 10 73 100 76 39 22 18 86 9 29 99 54 48 17 94 45 72 80 60 32 4 12 63 51 82 36 88 75 33 95 20 41 83 30 56 19 66 89 52 93 13 79 3 65 14 37 74 38 15 96 64 47 28 31 34 25 23 1 7 2 90 55
//245: 48 27 96 32 85 5 20 70 91 13 78 69 67 12 26 54 25 58 4 9 34 49 40 72 89 47 56 7 15 88 57 94 16 52 79 92 18 8 33 43 84 90 14 53 73 39 97 23 37 30 21 29 71 38 3 6 44 76 68 87 61 24 46 66 60 74 1 10 99 2 80 41 95 28 17 35 98 63 86 55 83 77 22 11 64 81 45 59 36 93 19 51 100 82 50 62 31 65 75 42