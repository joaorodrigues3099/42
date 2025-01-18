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
#include "game.h"

void	ft_file_to_map_matrix2(t_list *map_list, t_map *map)
{
	t_list	*current;
	int		i;

	map->height = ft_lstsize(map_list);
	map->width = 0;
	if (map_list)
		map->width = (int)ft_strlen(map_list->content);
	map->map = (char **)malloc((map->width + 1) * sizeof(char *));
	if (!map->map)
	{
		ft_lstclear(&map_list, free);
		exit (ft_print_error(E_MEMORY_ALLOC));
	}
	current = map_list;
	i = 0;
	while (current)
	{
		map->map[i++] = ft_strtrim(current->content, "\n");
		current = current->next;
	}
	map->map[i] = NULL;
	ft_lstclear(&map_list, NULL);
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
		ft_lstadd_back(&map_list, ft_lstnew(ft_strtrim(line, "\n")));
	}
	close (fd);
	ft_file_to_map_matrix2(map_list, map);
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

void	ft_get_map(t_game *game, const char *filename)
{
	ft_check_map_file(filename);
	ft_file_to_map_matrix(filename, &game->map);
}