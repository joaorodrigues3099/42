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

int	ft_lst_sorted(const t_list *lst)
{
	while (lst->next)
	{
		if (ft_lstget_int(lst) > ft_lstget_int(lst->next))
			return (0);
		lst = lst->next;
	}
	return (1);
}

static int	ft_lst_no_dups(t_list *lst)
{
	t_list	*current;
	t_list	*temp;

	current = lst;
	while (current)
	{
		temp = lst;
		while (temp != current)
		{
			if (ft_lstget_int(temp) == ft_lstget_int(current))
				return (0);
			temp = temp->next;
		}
		current = current->next;
	}
	return (1);
}

static void	ft_fill_lst(t_list **lst, char **av, const int *size)
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
			ft_lstclear(lst, NULL);
			return ;
		}
		ft_lstadd_back(lst, ft_lstnew_int((int)atoll));
		i++;
	}
}

t_list	*ft_get_input(char **av, const int ac, int *size)
{
	t_list	*lst;
	char	**split;

	lst = NULL;
	if (ac == 2)
	{
		split = ft_split(av[1], ' ');
		if (!split)
			return (NULL);
		while (split[*size])
			(*size)++;
		ft_fill_lst(&lst, split, size);
		ft_free_matrix((void **)split, *size - 1);
	}
	else if (ac > 2)
	{
		*size = ac - 1;
		ft_fill_lst(&lst, av + 1, size);
	}
	if (!ft_lst_no_dups(lst))
		ft_lstclear(&lst, NULL);
	return (lst);
}
