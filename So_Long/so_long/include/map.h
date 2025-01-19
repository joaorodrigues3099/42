/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:58:21 by joao-alm          #+#    #+#             */
/*   Updated: 2025/01/18 16:58:21 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

typedef struct s_map t_map;

typedef struct	s_flood_fill
{
	int			x;
	int			y;
	int			collected;
	int			depth;
}				t_flood_fill;

// Define the visited array structure
typedef struct s_visited {
	bool **visited; // 2D array to track visited positions
	int width;
	int height;
} t_visited;


void	ft_parse_map(t_game *game);
int		ft_flood_fill(t_game *game, int x, int y, int *collected, int depth);

#endif //MAP_H
