/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 21:25:51 by joao-alm          #+#    #+#             */
/*   Updated: 2024/12/18 21:25:51 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_list.h"
#include "ft_printf.h"
#include "lib_string.h"
#include "quicksort.h"

static int	ft_cmp_ops(const t_list *curr_op, char *s1, char *s2)
{
	return ((!ft_strncmp(curr_op->content, s1, 3) &&
		!ft_strncmp(curr_op->next->content, s2, 3)) ||
		(!ft_strncmp(curr_op->content, s2, 3) &&
		!ft_strncmp(curr_op->next->content, s1, 3)));
}

static void	ft_merge_ops(t_list **ops, t_list *curr_op, const char *new_op)
{
	curr_op->content = (char *)new_op;
	ft_lstdel_safely(ops, curr_op->next, NULL);
}

void	ft_clean_ops(t_list **ops)
{
	t_list	*curr_op;
	t_list	*temp;

	curr_op = *ops;
	while (curr_op && curr_op->next)
	{
		if (ft_cmp_ops(curr_op, "sa", "sb"))
			ft_merge_ops(ops, curr_op, "ss");
		else if (ft_cmp_ops(curr_op, "ra", "rb"))
			ft_merge_ops(ops, curr_op,  "rr");
		else if (ft_cmp_ops(curr_op, "rra", "rrb"))
			ft_merge_ops(ops, curr_op,  "rrr");
		else if (ft_cmp_ops(curr_op, "ra", "rra") ||
				 ft_cmp_ops(curr_op, "rb", "rrb"))
		{
			temp = curr_op->next->next;
			ft_lstdel_safely(ops, curr_op, NULL);
			ft_lstdel_safely(ops, curr_op->next, NULL);
			curr_op = temp;
		}
		else
			curr_op = curr_op->next;
	}
}

void	ft_print_ops(const t_list *ops)
{
	while (ops)
	{
		ft_printf("%s\n", (char *)ops->content);
		ops = ops->next;
	}
}