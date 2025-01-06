/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:10:57 by joao-alm          #+#    #+#             */
/*   Updated: 2024/07/31 18:46:33 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

bool	ft_check(t_map *map, int x, int y, int expand)
{
	int	var_x;
	int	var_y;

	var_x = x;
	var_y = y;
	while (var_y <= (y + expand))
	{
		if (var_y >= map->rows)
			return (false);
		var_x = x;
		while (var_x <= (x + expand))
		{
			if (var_x >= map->cols)
				return (false);
			if (map->map[var_y][var_x] == map->obstacle)
				return (false);
			var_x++;
		}
		var_y++;
	}
	return (true);
}

void	ft_expand(t_map *map, int x, int y, t_square *square)
{
	int	expand;

	expand = 0;
	while (ft_check(map, x, y, expand))
		expand++;
	if (expand > square->size)
	{
		square->x = x;
		square->y = y;
		square->size = expand;
	}
}

void	ft_print_result(t_map *map, t_square *square)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < square->size)
	{
		while (i < square->size)
		{
			map->map[square->y + j][square->x + i] = map->full;
			i++;
		}
		i = 0;
		j++;
	}
}

void	ft_solve(t_map *map)
{
	int			i;
	int			j;
	t_square	square;

	square.size = 0;
	square.x = 0;
	square.y = 0;
	i = 0;
	j = 0;
	while (j < map->rows)
	{
		i = 0;
		while (i < map->cols)
		{
			ft_expand(map, i, j, &square);
			i++;
		}
		j++;
	}
	ft_print_result(map, &square);
}
