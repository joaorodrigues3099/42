/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:59:00 by joao-alm          #+#    #+#             */
/*   Updated: 2025/01/13 10:59:00 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

typedef struct s_map
{
	char		**map;
	int			width;
	int			height;
	int			exit_x;
	int			exit_y;
	int			n_collectibles;
	int			n_players;
	int			n_exits;
}				t_map;

typedef struct s_player
{
	int			x;
	int			y;
	int			sprite;
	int			glasses;
}				t_player;

typedef struct s_enemy
{
	int			x;
	int			y;
	int			direction;
	int			speed;
	int			active;
}				t_enemy;

typedef struct s_game
{
	t_map		map;
	t_player	player;
	int			n_moves;
	void		**sprites;
	int			n_sprites;
	void		**counter_sprites;
	int			n_counter_sprites;
	void		*mlx;
	void		*win;
}				t_game;

void			ft_window(t_game *game);

#endif // GAME_H
