/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:42:15 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/16 13:28:33 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	int		*tab;
	int		size;
	//int		**quartiles;

	tab = ft_get_tab(ac, av, &size);
	if (!tab)
		return (ft_print_error(), 1);
	if (ft_tab_dups(tab, size))
		return (ft_print_error(), 1);
	if (ft_tab_sorted(tab, size))
		return (0);
	for (int i = 0; i < size; i++)
		printf("%d\n", tab[i]);
	return (0);
}
