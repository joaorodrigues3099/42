/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:52:47 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/18 09:52:47 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"
#include "../includes/push_swap.h"
#include <stdio.h>

void	test_print_lsts(t_list *lst_a, t_list *lst_b)
{
	printf("List A: ");
	while (lst_a)
	{
		printf("%d -> ", *((int *)lst_a->content));
		lst_a = lst_a->next;
	}
	printf("NULL\n");
	printf("List B: ");
	while (lst_b)
	{
		printf("%d -> ", *((int *)lst_b->content));
		lst_b = lst_b->next;
	}
	printf("NULL\n");
}

void	test_print_tab(int *tab, int size)
{
	printf("Tab: ");
	for (int i = 0; i < size; i++)
	{
		if (i < size -1)
			printf("%d -> ", tab[i]);
		else
			printf("%d\n", tab[i]);
	}
}
