/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:49:15 by joao-alm          #+#    #+#             */
/*   Updated: 2024/12/04 16:49:15 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "pushswap.h"
#include "lib_list.h"
#include "lib_conversion.h"
#include "lib_memory.h"
#include "lib_string.h"

static void	ft_fill_lst(t_list **lst, char **av, const int *size, const int alloc)
{
	int			i;
	long long	atoll;
	int			checker;

	i = 0;
	while (i < *size)
	{
		checker = 1;
		atoll = ft_atoll_valid(av[i], INT_MIN, INT_MAX, &checker);
		if (checker == 0)
		{
			if (alloc == 1)
				ft_free_matrix((void **)av, i - 1);
			ft_lstclear(lst, NULL);
			return ;
		}
		ft_lstadd_back(lst, ft_lstnew_int((int)atoll));
		i++;
	}
}

void	ft_get_input(t_list **lst, char **av, const int ac, int *size)
{
	char	**split;

	if (ac == 2)
	{
		split = ft_split(av[1], ' ');
		if (!split)
			return ;
		while (split[*size])
			(*size)++;
		ft_fill_lst(lst, split, size, 1);
		ft_free_matrix((void **)split, *size - 1);
	}
	else if (ac > 2)
	{
		*size = ac - 1;
		ft_fill_lst(lst, av + 1, size, 0);
	}
}
