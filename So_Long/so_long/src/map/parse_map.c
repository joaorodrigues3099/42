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
#include "so_long.h"

int ft_r_valid_path(char **map, int x, int y, struct s_floodfill *s_ffill)
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
	if (ft_r_valid_path(map, x + 1, y, s_ffill) ||
	   ft_r_valid_path(map, x - 1, y, s_ffill) ||
	   ft_r_valid_path(map, x, y + 1, s_ffill) ||
	   ft_r_valid_path(map, x, y - 1, s_ffill))
		return (1);
	return (0);
}

void	ft_init_info(t_map *map)
{
	map->n_collectibles = 0;
	map->n_players = 0;
	map->player.x = 0;
	map->player.y = 0;
	map->n_exits = 0;
}

void	ft_parse_character(char c, int x, int y, t_map *map)
{
	if ((x <= 0 || x >= (int)map->size.x -1 || y <= 0 || y >= (int)map->size.y -1)
		&& c != '1')
		exit (ft_print_error(E_MAP_NOT_SURROUNDED));
	if (c == 'P')
	{
		map->player.x = x;
		map->player.y = y;
		map->n_players++;
		if (map->n_players > 1)
			exit (ft_print_error(E_MULTIPLE_STARTS));
	}
	else if (c == 'C')
		map->n_collectibles++;
	else if (c == 'E')
		map->n_exits++;
	else if (c != '0' && c != '1')
		exit (ft_print_error(E_INVALID_CHARACTER));
	if (map->n_exits > 1)
		exit (ft_print_error(E_MULTIPLE_EXITS));
}

void	ft_check_characters(t_map *map)
{
	int	x;
	int	y;

	ft_init_info(map);
	y = -1;
	while (++y < (int)map->size.y)
	{
		if ((int)ft_strlen(map->map[y]) != map->size.x)
			exit (ft_print_error(E_MAP_NOT_RECTANGLE));
		x = -1;
		while (++x < (int)map->size.x)
			ft_parse_character(map->map[y][x], x, y, map);
	}
	if (map->n_players < 1)
		exit (ft_print_error(E_NO_START));
	if (map->n_collectibles < 1)
		exit (ft_print_error(E_NO_COLLECTIBLE));
	if (map->n_exits < 1)
		exit (ft_print_error(E_NO_EXIT));
}
