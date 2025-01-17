/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:57:20 by joao-alm          #+#    #+#             */
/*   Updated: 2025/01/15 16:33:41 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <X11/X.h>

#include "so_long.h"

void	ft_window(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map.size.x * TILE_SIZE, game->map.size.y * TILE_SIZE, "so_long");
	load_sprites(game);
	render_map(game);
	mlx_hook(game->win, KeyPress, KeyPressMask, ft_handle_keys, game);
	mlx_hook(game->win, ClientMessage, LeaveWindowMask, ft_press_x, game);
	mlx_loop(game->mlx);
}
