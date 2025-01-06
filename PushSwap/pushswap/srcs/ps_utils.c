/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:05:47 by joao-alm          #+#    #+#             */
/*   Updated: 2024/12/27 14:05:47 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

#include "lib_write.h"
#include "pushswap.h"

void	ft_error(t_ps *data)
{
	if (data)
		ft_free_pushswap(data);
	ft_putendl_fd("Error", STDERR_FILENO);
	exit (EXIT_FAILURE);
}

void	ft_init_pushswap(t_ps *ps, t_list *lst, int size)
{
	ps->a_top = (t_stack){lst, size};
	ps->a_bot = (t_stack){NULL, 0};
	ps->b_top = (t_stack){NULL, 0};
	ps->b_bot = (t_stack){NULL, 0};
	ps->ops = NULL;
}

void	ft_free_pushswap(t_ps *pushswap)
{
	ft_lstclear(&pushswap->a_top.lst, NULL);
	ft_lstclear(&pushswap->a_bot.lst, NULL);
	ft_lstclear(&pushswap->b_top.lst, NULL);
	ft_lstclear(&pushswap->b_bot.lst, NULL);
	ft_lstclear(&pushswap->ops, NULL);
}
