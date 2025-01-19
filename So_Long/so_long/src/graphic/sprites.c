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
#include "game.h"

void	ft_original_player_sprite(t_game *game, int x, int y)
{
	if (game->map.map[y - 1][x] == '0')
		game->player.sprite = PLAYER_UP;
	else if (game->map.map[y][x - 1] == '0')
		game->player.sprite = PLAYER_LEFT;
	else if (game->map.map[y + 1][x] == '0')
		game->player.sprite = PLAYER_DOWN;
	else if (game->map.map[y][x + 1] == '0')
		game->player.sprite = PLAYER_RIGHT;
}

void	load_sprites(t_game *game)
{
	int	width;
	int	height;
	int	i;
	ft_original_player_sprite(game, game->player.x, game->player.y);
	game->sprites = malloc(N_SPRITES * sizeof(void *));
	width = TILE_SIZE;
	height = TILE_SIZE;
	game->sprites[WALL] = mlx_xpm_file_to_image(game->mlx, "assets/asteroid.xpm", &width, &height);
	game->sprites[FLOOR] = mlx_xpm_file_to_image(game->mlx, "assets/space.xpm", &width, &height);
	game->sprites[PLAYER_UP] = mlx_xpm_file_to_image(game->mlx, "assets/spaceship_up.xpm", &width, &height);
	game->sprites[PLAYER_LEFT] = mlx_xpm_file_to_image(game->mlx, "assets/spaceship_left.xpm", &width, &height);
	game->sprites[PLAYER_DOWN] = mlx_xpm_file_to_image(game->mlx, "assets/spaceship_down.xpm", &width, &height);
	game->sprites[PLAYER_RIGHT] = mlx_xpm_file_to_image(game->mlx, "assets/spaceship_right.xpm", &width, &height);
	game->sprites[COLLECTIBLE] = mlx_xpm_file_to_image(game->mlx, "assets/star.xpm", &width, &height);
	game->sprites[MAP_EXIT] = mlx_xpm_file_to_image(game->mlx, "assets/blackhole.xpm", &width, &height);
	i = -1;
	while (++i < N_SPRITES)
		if (!game->sprites[i])
			exit (1);
}

void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.height)
		{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->sprites[FLOOR], x * TILE_SIZE, y * TILE_SIZE + COUNTER_SIZE);
			else if (game->map.map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->sprites[WALL], x * TILE_SIZE, y * TILE_SIZE + COUNTER_SIZE);
			else if (game->map.map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->sprites[game->player.sprite], x * TILE_SIZE, y * TILE_SIZE + COUNTER_SIZE);
			else if (game->map.map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->sprites[COLLECTIBLE], x * TILE_SIZE, y * TILE_SIZE + COUNTER_SIZE);
			else if (game->map.map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->sprites[MAP_EXIT], x * TILE_SIZE, y * TILE_SIZE + COUNTER_SIZE);
			x++;
		}
		y++;
	}
}
