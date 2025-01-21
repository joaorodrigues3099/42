/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:18:42 by joao-alm          #+#    #+#             */
/*   Updated: 2025/01/15 18:18:42 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_codes.h"
#include "game.h"
#include "graphic.h"
#include "mlx.h"
#include <stdlib.h>

static void	ft_load_sprites2(t_game *game, char *sprite_addr[])
{
	int	width;
	int	height;
	int	i;

	game->sprites = malloc(sizeof(void *) * N_SPRITES);
	if (!game->sprites)
		ft_free_exit(game, E_MEMORY_ALLOC);
	width = TILE_SIZE;
	height = TILE_SIZE;
	i = -1;
	while (++i < N_SPRITES)
		game->sprites[i] = mlx_xpm_file_to_image(game->mlx, sprite_addr[i],
				&width, &height);
}

static void	ft_load_sprites(t_game *game)
{
	int	i;

	ft_load_sprites2(game, (char *[]){"assets/face/face_up.xpm",
		"assets/face/face_left.xpm", "assets/face/face_down.xpm",
		"assets/face/face_right.xpm", "assets/element/norminette.xpm",
		"assets/element/white.xpm", "assets/element/pass.xpm",
		"assets/element/42.xpm", "assets/element/job.xpm"});
	i = -1;
	while (++i < N_SPRITES)
		if (!game->sprites[i])
			ft_free_exit(game, E_SPRITES_MISSING);
}

static void	ft_put_image(t_game *game, void *image_ptr, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, image_ptr, x * TILE_SIZE, y
		* TILE_SIZE);
}

void	ft_render_map(t_game *game)
{
	int	y;
	int	x;

	ft_load_sprites(game);
	game->n_sprites = N_SPRITES;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.map[y][x] == '0')
				ft_put_image(game, game->sprites[FLOOR], x, y);
			else if (game->map.map[y][x] == '1')
				ft_put_image(game, game->sprites[WALL], x, y);
			else if (game->map.map[y][x] == 'P')
				ft_put_image(game, game->sprites[PLAYER_UP], x, y);
			else if (game->map.map[y][x] == 'C')
				ft_put_image(game, game->sprites[COLLECTIBLE], x, y);
			else if (game->map.map[y][x] == 'E')
				ft_put_image(game, game->sprites[MAP_EXIT_CLOSED], x, y);
			x++;
		}
		y++;
	}
}
