/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:01:30 by joao-alm          #+#    #+#             */
/*   Updated: 2025/01/21 13:35:50 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_codes.h"
#include "game.h"
#include "graphic/graphic.h"
#include "lib_memory.h"
#include "lib_string.h"
#include "mlx.h"
#include <lib_print.h>
#include <unistd.h>

static void	ft_puterr(const char *error)
{
	write(2, "Error\n", 6);
	write(2, PINK, ft_strlen(PINK));
	write(2, error, ft_strlen(error));
	write(2, PINK, ft_strlen(RESET));
}

static void	ft_print_error2(const int err_code)
{
	if (err_code == E_MAP_NOT_SURROUNDED)
		ft_puterr("Map is not surrounded by walls\n");
	else if (err_code == E_INVALID_CHARACTER)
		ft_puterr("Only ('0', '1', 'P', 'C', 'E' allowed\n");
	else if (err_code == E_MULTIPLE_STARTS)
		ft_puterr("Only one player start ('P') allowed\n");
	else if (err_code == E_MULTIPLE_EXITS)
		ft_puterr("Only one exit ('E') allowed\n");
	else if (err_code == E_NO_START)
		ft_puterr("One player start ('P') is required\n");
	else if (err_code == E_NO_EXIT)
		ft_puterr("One exit ('E') is required\n");
	else if (err_code == E_NO_COLLECTIBLE)
		ft_puterr("At least one collectible ('C') is required\n");
	else if (err_code == E_OBSTRUCTED_PATH)
		ft_puterr("Path to exit/object is obstructed\n");
}

int	ft_print_error(const int err_code)
{
	if (err_code == E_OK)
		return (0);
	if (err_code == E_INVALID_FD)
		ft_puterr("Invalid fd\n");
	else if (err_code == E_MEMORY_ALLOC)
		ft_puterr("Memory allocation failed\n");
	else if (err_code == E_INVALID_FILE)
		ft_puterr("Invalid map file\n");
	else if (err_code == E_INVALID_TYPE)
		ft_puterr("Invalid map file type\n");
	else if (err_code == E_INVALID_FORMAT)
		ft_puterr("Format: ./so_long <MAP FILE PATH>\n");
	else if (err_code == E_MAP_NOT_RECTANGLE)
		ft_puterr("Map is not rectangle\n");
	else if (err_code == E_SPRITES_MISSING)
		ft_puterr("Sprite file not found\n");
	else
		ft_print_error2(err_code);
	return (err_code);
}

static void	ft_free_sprites(t_game *game, void **sprite_ptr, int n_sprites)
{
	if (sprite_ptr)
	{
		while (n_sprites--)
			if (sprite_ptr[n_sprites])
				mlx_destroy_image(game->mlx, sprite_ptr[n_sprites]);
		free(sprite_ptr);
		game->sprites = NULL;
	}
}

void	ft_free_exit(t_game *game, const int err_code)
{
	ft_free_matrix((void **)game->map.map, game->map.height - 1);
	ft_free_sprites(game, game->sprites, game->n_sprites);
	ft_free_sprites(game, game->counter_sprites, game->n_counter_sprites);
	if (game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	exit(ft_print_error(err_code));
}
