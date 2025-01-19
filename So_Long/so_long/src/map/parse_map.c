/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:15:41 by joao-alm          #+#    #+#             */
/*   Updated: 2025/01/14 16:15:41 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>

#include "lib_string.h"
#include "error_codes.h"
#include "game.h"
#include "map.h"

void	ft_init_map(t_map *map)
{
	map->n_collectibles = 0;
	map->n_exits = 0;
	map->n_players = 0;
	map->min_moves = INT_MAX;
}

void	ft_parse_single_character(const char c, const int x, const int y, t_game *game)
{
	if ((x <= 0 || x >= game->map.width -1 || y <= 0 || y >= game->map.height -1)
		&& c != '1')
		ft_free_exit(game, E_MAP_NOT_SURROUNDED);
	if (c == 'P')
	{
		game->player.x = x;
		game->player.y = y;
		game->map.n_players++;
		if (game->map.n_players > 1)
			ft_free_exit(game, E_MULTIPLE_STARTS);
	}
	else if (c == 'C')
		game->map.n_collectibles++;
	else if (c == 'E')
	{
		game->map.n_exits++;
		if (game->map.n_exits > 1)
			ft_free_exit(game, E_MULTIPLE_EXITS);
	}
	else if (c != '0' && c != '1')
		ft_free_exit(game, E_INVALID_CHARACTER);
}

void	ft_parse_map_characters(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->map.height)
	{
		if ((int)ft_strlen(game->map.map[y]) != game->map.width)
			ft_free_exit(game, E_MAP_NOT_RECTANGLE);
		x = -1;
		while (++x < game->map.width)
			ft_parse_single_character(game->map.map[y][x], x, y, game);
	}
	if (game->map.n_players < 1)
		ft_free_exit(game, E_NO_START);
	if (game->map.n_collectibles < 1)
		ft_free_exit(game, E_NO_COLLECTIBLE);
	if (game->map.n_exits < 1)
		ft_free_exit(game, E_NO_EXIT);
}

void	ft_parse_map(t_game *game)
{
	int	collected;

	collected = 0;
	ft_init_map(&game->map);
	ft_parse_map_characters(game);
	if (!ft_flood_fill(game, game->player.x, game->player.y, &collected, 0))
		ft_free_exit(game, E_OBSTRUCTED_PATH);
}