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

#include <stdlib.h>

#include "lib_string.h"
#include "error_codes.h"
#include "game.h"
#include "map.h"

int ft_flood_fill(char **map, int x, int y, t_ffill *ffill)
{
	if (x < 0 || map[y][x] == '\0' || y < 0 || !map[y]
		|| map[y][x] == '1')
		return (0);
	if (map[y][x] == 'C')
		s_ffill->collectibles--;
	if (map[y][x] == 'E')
	{
		s_ffill->exit_found = 1;
		if (!s_ffill->collectibles)
			return (1);
		return (0);
	}
	map[y][x] = '1';
	if (!s_ffill->collectibles && s_ffill->exit_found)
		return (1);
	if (ft_flood_fill(map, x + 1, y, s_ffill) ||
	   ft_flood_fill(map, x - 1, y, s_ffill) ||
	   ft_flood_fill(map, x, y + 1, s_ffill) ||
	   ft_flood_fill(map, x, y - 1, s_ffill))
		return (1);
	return (0);
}

void	ft_parse_character(const char c, const int x, const int y, t_game *game)
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
			ft_parse_character(game->map.map[y][x], x, y, game);
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
	char	**map_dup;
	int		valid_path;

	ft_init_map(&game->map);
	ft_parse_map_characters(game);
	map_dup = ft_duplicate_map(game->map.map);
	if (!map_dup)
		ft_free_exit(game, E_MEMORY_ALLOC);
	valid_path = ft_flood_fill(map_dup, game->player.x, game->player.y,
		&(t_ffill){game->map.n_collectibles, 0});
	free(map_dup);
	if (!valid_path)
		ft_free_exit(game, E_OBSTRUCTED_PATH);
}