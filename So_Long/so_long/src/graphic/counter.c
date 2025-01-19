/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:56:29 by joao-alm          #+#    #+#             */
/*   Updated: 2025/01/19 19:56:36 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "game.h"
#include "mlx.h"

void	load_counter_sprites(t_game *game)
{
	int	width;
	int	height;
	int	i;
	char	*sprites[] = {
		"assets/zero.xpm", "assets/one.xpm", "assets/two.xpm", "assets/three.xpm", "assets/four.xpm", "assets/five.xpm", "assets/six.xpm",
		"assets/seven.xpm", "assets/eight.xpm", "assets/nine.xpm", "assets/letter_m.xpm",
		"assets/letter_i.xpm", "assets/letter_n.xpm", "assets/letter_u.xpm", "assets/letter_o.xpm",
		"assets/letter_v.xpm", "assets/letter_e.xpm", "assets/letter_s.xpm", "assets/letter_y.xpm",
		"assets/letter_r.xpm", "assets/letter_space.xpm"
	};
	game->counter.counter = malloc(N_COUNTER_SPRITES * sizeof(void *));
	width = COUNTER_SIZE;
	height = COUNTER_SIZE;

	i = 0;
	while (i < N_COUNTER_SPRITES)
	{
		game->counter.counter[i] = mlx_xpm_file_to_image(game->mlx, sprites[i], &width, &height);
		if (!game->counter.counter[i])
			exit(1);
		i++;
	}
}

void	ft_render_counter(t_game *game)
{
	int	x;
	int	i;
	int	counter_string[] = {
		LETTER_M, LETTER_I, LETTER_N, LETTER_I, LETTER_M, LETTER_U, LETTER_M,
		LETTER_SPACE, LETTER_M, LETTER_O, LETTER_V, LETTER_E, LETTER_S,
		LETTER_SPACE, game->map.min_moves / 10, game->map.min_moves % 10
	};

	x = 0;
	i = 0;
	// Loop through the counter_string array to render each sprite
	while (i < (int)sizeof(counter_string) / (int)sizeof(counter_string[0]))
	{
		mlx_put_image_to_window(game->mlx, game->win, game->counter.counter[counter_string[i]], x * COUNTER_SIZE, 0);
		x++; // Increment x to place the next sprite
		i++; // Move to the next sprite
	}
}
