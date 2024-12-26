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

// Chunk
typedef struct s_chunk
{
	t_loc	loc;
	int		size;
}	t_chunk;

// Split
typedef struct s_split
{
	t_chunk	min;
	t_chunk	med;
	t_chunk	max;
}	t_split;

// Chunk Utils
t_list	*ft_get_chunk(t_ps pushswap, const t_chunk *chunk_data);
int		ft_chunk_value(const t_ps *pushswap, const t_chunk *chunk_data, int pos);

// Chunk Split
void	ft_chunk_split(t_ps *pushswap, t_chunk *src, t_split *dest);

// Pivots
void	ft_get_pivots(int *pivots, const t_ps *pushswap, const t_chunk *chunk_data);

// Move
int		move_from_to(t_ps *pushswap, const t_loc from, const t_loc to);

// Chunk Sort
void	ft_chunk_sort_one(t_ps *pushswap, t_chunk *chunk);
void	ft_chunk_sort_two(t_ps *pushswap, t_chunk *chunk);
void	ft_chunk_sort_three(t_ps *pushswap, t_chunk *to_sort);

#endif //PUSHSWAP_H
