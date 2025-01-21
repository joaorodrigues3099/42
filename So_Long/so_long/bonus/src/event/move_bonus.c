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

#include "error_codes.h"
#include "event.h"
#include "game.h"
#include "graphic_bonus.h"
#include "mlx.h"
#include <lib_print.h>
#include <stdlib.h>

static void	ft_move(t_game *game, const t_point *new_pos,
	const t_point *old_pos)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->sprites[game->player.sprite],
		new_pos->x * TILE_SIZE, new_pos->y * TILE_SIZE + HEADER_SIZE);
	game->map.map[new_pos->y][new_pos->x] = 'P';
	mlx_put_image_to_window(game->mlx, game->win, game->sprites[FLOOR],
		old_pos->x * TILE_SIZE, old_pos->y * TILE_SIZE + HEADER_SIZE);
	game->map.map[old_pos->y][old_pos->x] = '0';
	game->player.x = new_pos->x;
	game->player.y = new_pos->y;
	game->n_moves++;
	ft_update_counter(game);
}

void	ft_update_player_pos(t_game *game, int x_offset, int y_offset)
{
	t_point	new_pos;

	new_pos.x = game->player.x + x_offset;
	new_pos.y = game->player.y + y_offset;
	if (new_pos.x < 0 || new_pos.x >= game->map.width || new_pos.y < 0
		|| new_pos.y >= game->map.height)
		return ;
	if (game->map.map[new_pos.y][new_pos.x] == '0')
		ft_move(game, &new_pos, &(t_point){game->player.x, game->player.y});
	else if (game->map.map[new_pos.y][new_pos.x] == 'C')
	{
		ft_move(game, &new_pos, &(t_point){game->player.x, game->player.y});
		game->map.n_collectibles--;
		if (game->map.n_collectibles == 0)
			mlx_put_image_to_window(game->mlx, game->win,
				game->sprites[MAP_EXIT_OPEN], game->map.exit_x * TILE_SIZE,
				game->map.exit_y * TILE_SIZE + HEADER_SIZE);
	}
	else if (game->map.map[new_pos.y][new_pos.x] == 'E'
		&& game->map.n_collectibles == 0)
	{
		ft_printf("Congratulations, you've won!\n");
		ft_free_exit(game, E_OK);
	}
}
