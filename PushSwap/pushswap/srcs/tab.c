/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:56:47 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/16 17:56:47 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/strmanp.h"
#include "../libft/includes/memlib.h"
#include <limits.h>

int	*ft_string_to_tab(char *str, int *size)
{
	int		*tab;
	char	**split;
	int		n_membs;
	int		i;
	long	checker;

	split = ft_split(str, ' ');
	n_membs = 0;
	while (split[n_membs])
		n_membs++;
	*size = n_membs;
	tab = (int *)malloc(n_membs * sizeof(int));
	i = -1;
	while (++i < n_membs)
	{
		checker = ft_atoi_check_int(split[i]);
		if (checker < INT_MIN)
			return (ft_free_matrix((void **)split, i-1), free(tab), NULL);
		tab[i] = checker;
	}
	ft_free_matrix((void **)split, n_membs-1);
	return (tab);
}

int *ft_matrix_to_tab(char **av, int ac, int *size)
{
	int		*tab;
	int		i;
	long	checker;

	*size = ac - 1;
	tab = (int *)malloc(*size);
	i = -1;
	while (++i < *size)
	{
		checker = ft_atoi_check_int(av[1 + i]);
		if (checker < INT_MIN)
			return (free(tab), NULL);
		tab[i] = checker;
	}
	return (tab);
}

int	*ft_get_tab(int ac, char **av, int *size)
{
	int		*tab;

	if (ac == 2)
		tab = ft_string_to_tab(av[1], size);
	else
		tab = ft_matrix_to_tab(av, ac, size);
	return (tab);
}
