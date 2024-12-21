/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:45:15 by joao-alm          #+#    #+#             */
/*   Updated: 2024/12/04 16:45:15 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
#define PUSHSWAP_H

#include "pushswap.h"

enum e_bottop
{
	TOP,
	BOT
};

typedef struct s_chunk
{
	t_loc	loc;
	int		size;
}	t_chunk;

typedef struct s_split
{
	t_chunk	min;
	t_chunk	med;
	t_chunk	max;
}	t_split;

void	ft_chunk_to_tab(int *tab, const t_ps *pushswap, const t_chunk *chunk_data);
int		ft_chunk_value(const t_ps *pushswap, const t_chunk *chunk_data, int pos);
int		ft_chunck_max(const t_ps *pushswap, const t_chunk *chunk);

void	ft_chunk_split(t_ps *pushswap, t_chunk *src, t_split *dest);

int		move_from_to(t_ps *pushswap, const t_loc from, const t_loc to);

void	ft_chunk_sort_one(t_ps *pushswap, t_chunk *chunk);
void	ft_chunk_sort_two(t_ps *pushswap, t_chunk *chunk);
void	ft_chunk_sort_three(t_ps *pushswap, t_chunk *to_sort);

#endif //PUSHSWAP_H
