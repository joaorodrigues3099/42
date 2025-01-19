/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:04:57 by joao-alm          #+#    #+#             */
/*   Updated: 2025/01/19 17:04:57 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "map.h"

int ft_flood_fill(t_game *game, int x, int y, int *collected, int depth)
{
	char	temp;

	if (x < 0 || game->map.map[y][x] == '\0' || y < 0 || ! game->map.map[y]
		||  game->map.map[y][x] == '1')
		return (0);
	if ( game->map.map[y][x] == 'C')
		(*collected)++;
	if ( game->map.map[y][x] == 'E')
	{
		if (*collected == game->map.n_collectibles)
		{
			if (depth < game->map.min_moves)
				game->map.min_moves = depth;
			return (1);
		}
		return (0);
	}
	temp = game->map.map[y][x];
	game->map.map[y][x] = '1';
	if (ft_flood_fill(game, x + 1, y, collected, depth + 1) ||
	   ft_flood_fill(game, x - 1, y, collected, depth + 1) ||
	   ft_flood_fill(game, x, y + 1, collected, depth + 1) ||
	   ft_flood_fill(game, x, y - 1, collected, depth + 1))
	{
		game->map.map[y][x] = temp;
		return (1);
	}
	game->map.map[y][x] = temp;
	return (0);
}


