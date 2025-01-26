/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:14:12 by joao-alm          #+#    #+#             */
/*   Updated: 2025/01/20 16:14:12 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "lib_string.h"
#include <stdlib.h>

void	ft_init_map(t_game *game)
{
	game->map.n_collectibles = 0;
	game->map.n_exits = 0;
	game->map.n_players = 0;
	game->sprites = NULL;
	game->counter_sprites = NULL;
	game->mlx = NULL;
	game->win = NULL;
}

char	**ft_duplicate_map(char **map)
{
	int		i;
	int		rows;
	char	**copy;

	rows = 0;
	while (map[rows])
		rows++;
	copy = (char **)malloc((rows + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	i = -1;
	while (++i < rows)
		copy[i] = ft_strdup(map[i]);
	copy[i] = NULL;
	return (copy);
}
