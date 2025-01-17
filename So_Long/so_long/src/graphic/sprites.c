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

void	ft_original_player_sprite(t_game *game, t_point *player)
{
	if (game->map.map[player->y - 1][player->x] == '0')
		game->map.player_sprite = PLAYER_UP;
	else if (game->map.map[player->y][player->x - 1] == '0')
		game->map.player_sprite = PLAYER_LEFT;
	else if (game->map.map[player->y + 1][player->x] == '0')
		game->map.player_sprite = PLAYER_DOWN;
	else if (game->map.map[player->y][player->x + 1] == '0')
		game->map.player_sprite = PLAYER_RIGHT;
}

void	load_sprites(t_game *game)
{
	int	width;
	int	height;
	int	i;
	ft_original_player_sprite(game, &game->map.player);
	for (int j = 0; j < game->map.size.y; j++)
		ft_printf("%s\n", game->map.map[j]);
	game->map.sprites = malloc(N_SPRITES * sizeof(void *));
	width = TILE_SIZE;
	height = TILE_SIZE;
	game->map.sprites[WALL] = mlx_xpm_file_to_image(game->mlx, "assets/asteroid.xpm", &width, &height);
	game->map.sprites[FLOOR] = mlx_xpm_file_to_image(game->mlx, "assets/space.xpm", &width, &height);
	game->map.sprites[PLAYER_UP] = mlx_xpm_file_to_image(game->mlx, "assets/spaceship_up.xpm", &width, &height);
	game->map.sprites[PLAYER_LEFT] = mlx_xpm_file_to_image(game->mlx, "assets/spaceship_left.xpm", &width, &height);
	game->map.sprites[PLAYER_DOWN] = mlx_xpm_file_to_image(game->mlx, "assets/spaceship_down.xpm", &width, &height);
	game->map.sprites[PLAYER_RIGHT] = mlx_xpm_file_to_image(game->mlx, "assets/spaceship_right.xpm", &width, &height);
	game->map.sprites[COLLECTIBLE] = mlx_xpm_file_to_image(game->mlx, "assets/star.xpm", &width, &height);
	game->map.sprites[MAP_EXIT] = mlx_xpm_file_to_image(game->mlx, "assets/blackhole.xpm", &width, &height);
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
				mlx_put_image_to_window(game->mlx, game->win, game->map.sprites[game->map.player_sprite], x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map.map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->map.sprites[COLLECTIBLE], x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map.map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->map.sprites[MAP_EXIT], x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}
