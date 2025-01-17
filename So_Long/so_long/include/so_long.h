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

#ifndef SO_LONG_H
#define SO_LONG_H

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

// MAP
struct			s_floodfill
{
	int	collectibles;
	int	exit_found;
};

typedef struct	s_map_info
{
	char	**map;
	t_point	size;
	int		n_collectibles;
	int		n_players;
	t_point	player;
	int		n_exits;
	void	**sprites;
	int		player_sprite;
}				t_map;

int		ft_r_valid_path(char **map, int x, int y, struct s_floodfill *s_ffill);
void	ft_check_characters(t_map *map);
void	ft_handle_map(t_map *map, const char *filename);


// GRAPHIC
#define TILE_SIZE 64

typedef struct	s_game
{
	t_map	map;
	void	*mlx;
	void	*win;
}				t_game;

enum	e_sprites
{
	WALL,
	FLOOR,
	PLAYER_UP,
	PLAYER_LEFT,
	PLAYER_DOWN,
	PLAYER_RIGHT,
	COLLECTIBLE,
	MAP_EXIT,
	N_SPRITES
};

enum	e_keycodes
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

void	ft_window(t_game *game);
void	load_sprites(t_game *game);
void	render_map(t_game *game);


// KEYS
int	ft_handle_keys(int keycode, t_game *game);
int	ft_press_x(t_game *game);

// MOVE
void	ft_update_player_pos(t_game *game, int x_offset, int y_offset);

#endif //SO_LONG_H
