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
#include "game.h"

void	ft_move(t_game *game, t_point *new_pos, t_point *old_pos)
{
	mlx_put_image_to_window(game->mlx, game->win, game->sprites[game->player.sprite],
		new_pos->x * TILE_SIZE, new_pos->y * TILE_SIZE + COUNTER_SIZE);
	game->map.map[new_pos->y][new_pos->x] = 'P';
	mlx_put_image_to_window(game->mlx, game->win, game->sprites[FLOOR],
		old_pos->x * TILE_SIZE, old_pos->y * TILE_SIZE + COUNTER_SIZE);
	game->map.map[old_pos->y][old_pos->x] = '0';
	game->player.x = new_pos->x;
	game->player.y = new_pos->y;
}

void	ft_update_player_pos(t_game *game, int x_offset, int y_offset)
{
	t_point	new_pos;

	new_pos.x = game->player.x + x_offset;
	new_pos.y = game->player.y + y_offset;

	// Check bounds
	if (new_pos.x < 0 || new_pos.x >= game->map.width ||
		new_pos.y < 0 || new_pos.y >= game->map.height)
		return;

	// Update player sprite based on movement direction
	if (x_offset == 0 && y_offset == -1) // Moving up
		game->player.sprite = PLAYER_UP;
	else if (x_offset == -1 && y_offset == 0) // Moving left
		game->player.sprite = PLAYER_LEFT;
	else if (x_offset == 0 && y_offset == 1) // Moving down
		game->player.sprite = PLAYER_DOWN;
	else if (x_offset == 1 && y_offset == 0) // Moving right
		game->player.sprite = PLAYER_RIGHT;
	mlx_put_image_to_window(game->mlx, game->win, game->sprites[game->player.sprite],
		game->player.x * TILE_SIZE, game->player.y * TILE_SIZE + COUNTER_SIZE);

	// Handle movement
	if (game->map.map[new_pos.y][new_pos.x] == '0')
		ft_move(game, &new_pos, &(t_point ){game->player.x, game->player.y});
	else if (game->map.map[new_pos.y][new_pos.x] == 'C')
	{
		ft_move(game, &new_pos, &(t_point ){game->player.x, game->player.y});
		game->map.n_collectibles--;
	}
	else if (game->map.map[new_pos.y][new_pos.x] == 'E' && game->map.n_collectibles == 0)
	{
		ft_printf("Congratulations, you've won!\n");
		exit(EXIT_SUCCESS);
	}
}
