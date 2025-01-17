/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:36:39 by joao-alm          #+#    #+#             */
/*   Updated: 2025/01/13 11:11:13 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "lib_string.h"
#include "lib_list.h"
#include "lib_gnl.h"

#include "error_codes.h"
#include "so_long.h"

void	ft_file_to_map_matrix2(t_list *map_list, t_map *map)
{
	t_list	*current;
	int		i;

	map->size.y = ft_lstsize(map_list);
	map->size.x = 0;
	if (map_list)
		map->size.x = (int)ft_strlen(ft_strtrim(map_list->content, "\n"));
	map->map = (char **)malloc((map->size.x + 1) * sizeof(char *));
	if (!map->map)
		exit (ft_print_error(E_MEMORY_ALLOC));
	current = map_list;
	i = 0;
	while (current)
	{
		map->map[i++] = ft_strtrim(current->content, "\n");
		current = current->next;
	}
	map->map[i] = NULL;
}

void	ft_file_to_map_matrix(const char *filename, t_map *map)
{
	t_list	*map_list;
	int		fd;
	char	*line;

	map_list = NULL;
	fd = open(filename, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_lstadd_back(&map_list, ft_lstnew(line));
	}
	close (fd);
	ft_file_to_map_matrix2(map_list, map);
	ft_lstclear(&map_list, NULL);
}

void	ft_check_map_file(const char *filename)
{
	int		fd;
	size_t	len;

	fd = open(filename, O_RDONLY);
	close (fd);
	if (fd < 0)
		exit(ft_print_error(E_INVALID_FD));
	len = ft_strlen(filename);
	if (len <= 4 || ft_strncmp(filename + len - 4, ".ber", 4) != 0)
		exit(ft_print_error(E_INVALID_TYPE));
}

char **duplicate_map(char **map)
{
	int i = -1;
	int rows = 0;
	char **copy;

	rows = 0;
	while (map[rows])
		rows++;
	copy = (char **)malloc((rows + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	while (++i < rows)
		copy[i] = ft_strdup(map[i]);
	copy[i] = NULL;
	return (copy);
}

void	ft_handle_map(t_map *map, const char *filename)
{
	ft_check_map_file(filename);
	ft_file_to_map_matrix(filename, map);
	ft_check_characters(map);
	if (!ft_r_valid_path(duplicate_map(map->map), map->player.x, map->player.y,
		&(struct s_floodfill){map->n_collectibles, 0}))
		exit(ft_print_error(E_OBSTRUCTED_PATH));
}