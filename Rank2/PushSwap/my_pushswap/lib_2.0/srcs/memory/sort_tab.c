/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 09:03:46 by joao-alm          #+#    #+#             */
/*   Updated: 2024/12/09 09:03:46 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	ft_sort_tab(int *tab, const int size)
{
	int	i;
	int j;
	int	temp;

	if (!tab)
		return ;
	j = -1;
	while (++j < size)
	{
		i = j;
		while (++i < size)
		{
			if (tab[j] > tab[i])
			{
				temp = tab[j];
				tab[j] = tab[i];
				tab[i] = temp;
			}
		}
	}
}
