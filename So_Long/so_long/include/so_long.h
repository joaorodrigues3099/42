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
	int		n_starts;
	t_point	start;
	int		n_exits;
	void	**sprites;
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
	PLAYER,
	COLLECTIBLE,
	MAP_EXIT,
	N_SPRITES
};

enum	e_keycodes
{
	KEY_ESC = 65307
};

void	ft_window(t_game *game);
void	load_sprites(t_game *game);
void	render_map(t_game *game);


// KEYS
int	ft_handle_keys(int keycode, t_game *game);
int	ft_press_x(t_game *game);

#endif //SO_LONG_H
