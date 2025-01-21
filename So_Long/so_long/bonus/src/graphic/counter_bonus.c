/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:18:36 by joao-alm          #+#    #+#             */
/*   Updated: 2025/01/21 09:18:36 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_codes.h"
#include "game.h"
#include "graphic_bonus.h"
#include "mlx.h"
#include <stdlib.h>

void	ft_update_counter(t_game *game)
{
	if (game->n_moves < 1000)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->counter_sprites[game->n_moves / 100], 0, 0);
		mlx_put_image_to_window(game->mlx, game->win,
			game->counter_sprites[(game->n_moves / 10) % 10], TILE_SIZE, 0);
		mlx_put_image_to_window(game->mlx, game->win,
			game->counter_sprites[game->n_moves % 10], 2 * TILE_SIZE, 0);
	}
}

static void	ft_load_counter_sprites2(t_game *game, char *sprite_addr[])
{
	int	width;
	int	height;
	int	i;

	game->counter_sprites = malloc(sizeof(void *) * 11);
	if (!game->counter_sprites)
		ft_free_exit(game, E_MEMORY_ALLOC);
	width = TILE_SIZE;
	height = TILE_SIZE;
	i = -1;
	while (++i < 11)
	{
		game->counter_sprites[i] = mlx_xpm_file_to_image(game->mlx,
				sprite_addr[i], &width, &height);
	}
}

static void	ft_load_counter_sprites(t_game *game)
{
	int	i;

	ft_load_counter_sprites2(game, (char *[]){"assets/digit/zero.xpm",
		"assets/digit/one.xpm", "assets/digit/two.xpm",
		"assets/digit/three.xpm", "assets/digit/four.xpm",
		"assets/digit/five.xpm", "assets/digit/six.xpm",
		"assets/digit/seven.xpm", "assets/digit/eight.xpm",
		"assets/digit/nine.xpm", "assets/digit/black.xpm"});
	i = -1;
	while (++i < 11)
		if (!game->counter_sprites[i])
			ft_free_exit(game, E_SPRITES_MISSING);
}

void	ft_render_counter(t_game *game)
{
	int	x;

	ft_load_counter_sprites(game);
	game->n_counter_sprites = 11;
	x = -1;
	while (++x < 3)
		mlx_put_image_to_window(game->mlx, game->win, game->counter_sprites[0],
			x * TILE_SIZE, 0);
	x--;
	while (++x < game->map.width)
		mlx_put_image_to_window(game->mlx, game->win, game->counter_sprites[10],
			x * TILE_SIZE, 0);
}
