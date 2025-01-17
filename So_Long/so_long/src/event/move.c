/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:01:15 by joao-alm          #+#    #+#             */
/*   Updated: 2025/01/17 17:01:15 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lib_print.h>
#include <stdlib.h>

#include "mlx.h"
#include "so_long.h"

void	ft_move(t_game *game, t_point *new_pos, t_point *old_pos)
{
	mlx_put_image_to_window(game->mlx, game->win, game->map.sprites[game->map.player_sprite],
		new_pos->x * TILE_SIZE, new_pos->y * TILE_SIZE);
	game->map.map[new_pos->y][new_pos->x] = 'P';
	mlx_put_image_to_window(game->mlx, game->win, game->map.sprites[FLOOR],
		old_pos->x * TILE_SIZE, old_pos->y * TILE_SIZE);
	game->map.map[old_pos->y][old_pos->x] = '0';
	game->map.player = *new_pos; // Update player position
}

void	ft_update_player_pos(t_game *game, int x_offset, int y_offset)
{
	t_point	new_pos;

	new_pos.x = game->map.player.x + x_offset;
	new_pos.y = game->map.player.y + y_offset;

	// Check bounds
	if (new_pos.x < 0 || new_pos.x >= game->map.size.x ||
		new_pos.y < 0 || new_pos.y >= game->map.size.y)
		return;

	// Update player sprite based on movement direction
	if (x_offset == 0 && y_offset == -1) // Moving up
		game->map.player_sprite = PLAYER_UP;
	else if (x_offset == -1 && y_offset == 0) // Moving left
		game->map.player_sprite = PLAYER_LEFT;
	else if (x_offset == 0 && y_offset == 1) // Moving down
		game->map.player_sprite = PLAYER_DOWN;
	else if (x_offset == 1 && y_offset == 0) // Moving right
		game->map.player_sprite = PLAYER_RIGHT;
	mlx_put_image_to_window(game->mlx, game->win, game->map.sprites[game->map.player_sprite],
		game->map.player.x * TILE_SIZE, game->map.player.y * TILE_SIZE);

	// Handle movement
	if (game->map.map[new_pos.y][new_pos.x] == '0')
		ft_move(game, &new_pos, &game->map.player);
	else if (game->map.map[new_pos.y][new_pos.x] == 'C')
	{
		ft_move(game, &new_pos, &game->map.player);
		game->map.n_collectibles--;
	}
	else if (game->map.map[new_pos.y][new_pos.x] == 'E' && game->map.n_collectibles == 0)
	{
		ft_printf("Congratulations, you've won!\n");
		exit(EXIT_SUCCESS);
	}
}
