/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:10:30 by joao-alm          #+#    #+#             */
/*   Updated: 2025/01/20 17:10:30 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

typedef struct s_game	t_game;

typedef struct s_point
{
	int					x;
	int					y;
}						t_point;

enum					e_keycodes
{
	KEY_ESC = 65307,
	KEY_W = 119,
	KEY_UP = 65362,
	KEY_A = 97,
	KEY_LEFT = 65361,
	KEY_S = 115,
	KEY_DOWN = 65364,
	KEY_D = 100,
	KEY_RIGHT = 65363
};

// keys
int						ft_handle_keys(int keycode, t_game *game);
int						ft_press_x(t_game *game);

// move
void					ft_update_player_pos(t_game *game, int x_offset,
							int y_offset);

#endif // EVENT_H
