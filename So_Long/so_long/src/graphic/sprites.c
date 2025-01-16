/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:18:42 by joao-alm          #+#    #+#             */
/*   Updated: 2025/01/15 18:18:42 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <lib_print.h>
#include <stdlib.h>

#include "mlx.h"
#include "so_long.h"

void	load_sprites(t_game *game)
{
	int	width;
	int	height;
	int	i;

	for (int j = 0; j < game->map.size.y; j++)
		ft_printf("%s\n", game->map.map[j]);
	game->map.sprites = malloc(N_SPRITES * sizeof(void *));
	width = TILE_SIZE;
	height = TILE_SIZE;
	game->map.sprites[WALL] = mlx_xpm_file_to_image(game->mlx, "assets/wall-resized.xpm", &width, &height);
	game->map.sprites[FLOOR] = mlx_xpm_file_to_image(game->mlx, "assets/floor-resized.xpm", &width, &height);
	game->map.sprites[PLAYER] = mlx_xpm_file_to_image(game->mlx, "assets/player-resized.xpm", &width, &height);
	game->map.sprites[COLLECTIBLE] = mlx_xpm_file_to_image(game->mlx, "assets/collectible-resized.xpm", &width, &height);
	game->map.sprites[MAP_EXIT] = mlx_xpm_file_to_image(game->mlx, "assets/exit-resized.xpm", &width, &height);
	i = -1;
	while (++i < N_SPRITES)
		if (!game->map.sprites[i])
			exit (1);
}

void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.size.y)
		{
		x = 0;
		while (x < game->map.size.x)
		{
			if (game->map.map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->map.sprites[FLOOR], x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map.map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->map.sprites[WALL], x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map.map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->map.sprites[PLAYER], x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map.map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->map.sprites[COLLECTIBLE], x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map.map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->map.sprites[MAP_EXIT], x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}
