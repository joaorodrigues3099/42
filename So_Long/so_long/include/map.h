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
#define MAP_H

typedef struct s_map t_map;

typedef struct	s_floodfill
{
	int	collectibles;
	int	exit_found;
}				t_ffill;

int		ft_r_valid_path(char **map, int x, int y, struct s_floodfill *s_ffill);
void	ft_check_characters(t_map *map);
void	ft_handle_map(t_map *map, const char *filename);

// Util
char	**ft_duplicate_map(char **map);
void	ft_init_map(t_map *map);

#endif //MAP_H
