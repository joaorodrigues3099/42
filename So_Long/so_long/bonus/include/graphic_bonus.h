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

#ifndef GRAPHIC_BONUS_H
# define GRAPHIC_BONUS_H

# define TILE_SIZE 64
# define HEADER_SIZE 64

typedef struct s_game	t_game;

enum					e_sprites
{
	PLAYER1,
	PLAYER2,
	PLAYER3,
	PLAYER4,
	PLAYER5,
	PLAYER6,
	PLAYER7,
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
int						ft_update_player_sprite(t_game *game);
void					ft_render_map(t_game *game);

// counter
void					ft_render_counter(t_game *game);
void					ft_update_counter(t_game *game);

#endif // GRAPHIC_BONUS_H
