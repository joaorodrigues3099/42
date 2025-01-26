/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:09:36 by joao-alm          #+#    #+#             */
/*   Updated: 2025/01/20 17:09:36 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H

# define TILE_SIZE 64

typedef struct s_game	t_game;

enum					e_sprites
{
	PLAYER_UP,
	PLAYER_LEFT,
	PLAYER_DOWN,
	PLAYER_RIGHT,
	WALL,
	FLOOR,
	COLLECTIBLE,
	MAP_EXIT_CLOSED,
	MAP_EXIT_OPEN,
	N_SPRITES
};

// window
void					ft_window(t_game *game);

// sprites
void					ft_render_map(t_game *game);

#endif // GRAPHIC_H
