/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunck_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 07:35:38 by joao-alm          #+#    #+#             */
/*   Updated: 2024/12/09 07:35:38 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>

#include "ft_printf.h"
#include "quicksort.h"

t_list	*ft_get_chunk(t_ps pushswap, const t_chunk *chunk_data)
{
	if (chunk_data->loc == A_TOP)
		return (pushswap.a_top.lst);
	if (chunk_data->loc == B_TOP)
		return (pushswap.b_top.lst);
	if (chunk_data->loc == A_BOT)
	{
		while (pushswap.a_bot.size-- - chunk_data->size > 0)
			pushswap.a_bot.lst = pushswap.a_bot.lst->next;
		return (pushswap.a_bot.lst);
	}
	if (chunk_data->loc == B_BOT)
	{
		while (pushswap.b_bot.size-- - chunk_data->size > 0)
			pushswap.b_bot.lst = pushswap.b_bot.lst->next;
		return (pushswap.b_bot.lst);
	}
	return (NULL);
}

void	ft_chunk_to_tab(int *tab, const t_ps *pushswap, const t_chunk *chunk_data)
{
	t_list	*chunk;
	int		i;

	chunk = ft_get_chunk(*pushswap, chunk_data);
	i = 0;
	while (chunk && i < chunk_data->size)
	{
		tab[i++] = ft_lstget_int(chunk);
		chunk = chunk->next;
	}
}

int	ft_chunk_value(const t_ps *pushswap, const t_chunk *chunk_data, const int pos)
{
	t_list	*current;
	int		i;

  	current = ft_get_chunk(*pushswap, chunk_data);
	if (chunk_data->loc == A_TOP || chunk_data->loc == B_TOP)
		i = pos;
	else
		i = chunk_data->size - 1 - pos;
	while (current && i-- > 0)
		current = current->next;
	return (ft_lstget_int(current));
}
