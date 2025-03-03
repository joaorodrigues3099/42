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
#include "graphic_bonus.h"
#include "lib_conversion.h"
#include "mlx.h"
#include <stdlib.h>
#include <unistd.h>

int	ft_update_player_sprite(t_game *game)
{
	if (game->player.glasses > 6)
		game->player.glasses = 0;
	usleep(1000);
	mlx_put_image_to_window(game->mlx, game->win,
		game->sprites[game->player.glasses], game->player.x * TILE_SIZE,
		game->player.y * TILE_SIZE + HEADER_SIZE);
	game->player.glasses++;
	return (0);
}

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

	ft_load_sprites2(game, (char *[]){"assets/glasses/glasses1.xpm",
		"assets/glasses/glasses2.xpm", "assets/glasses/glasses3.xpm",
		"assets/glasses/glasses4.xpm", "assets/glasses/glasses5.xpm",
		"assets/glasses/glasses6.xpm", "assets/glasses/glasses7.xpm",
		"assets/element/norminette.xpm", "assets/element/white.xpm",
		"assets/element/pass.xpm", "assets/element/42.xpm",
		"assets/element/job.xpm"});
	i = -1;
	while (++i < N_SPRITES)
		if (!game->sprites[i])
			ft_free_exit(game, E_SPRITES_MISSING);
	game->player.sprite = PLAYER1;
	game->n_sprites = N_SPRITES;
}

static void	ft_put_image(t_game *game, void *image_ptr, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, image_ptr, x * TILE_SIZE, y
		* TILE_SIZE + HEADER_SIZE);
}

void	ft_render_map(t_game *game)
{
	int	y;
	int	x;

	ft_load_sprites(game);
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
				ft_put_image(game, game->sprites[game->player.sprite], x, y);
			else if (game->map.map[y][x] == 'C')
				ft_put_image(game, game->sprites[COLLECTIBLE], x, y);
			else if (game->map.map[y][x] == 'E')
				ft_put_image(game, game->sprites[MAP_EXIT_CLOSED], x, y);
			x++;
		}
		y++;
	}
}
