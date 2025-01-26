/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:58:21 by joao-alm          #+#    #+#             */
/*   Updated: 2025/01/18 16:58:21 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_game	t_game;

typedef struct s_flood_fill
{
	int			collectibles;
	int			exit_found;
}				t_flood_fill;

// util
void					ft_init_map(t_game *game);
char					**ft_duplicate_map(char **map);

// parse_map
void					ft_parse_map(t_game *game);

// get_map
void					ft_get_map(t_game *game, const char *filename);

#endif // MAP_H
