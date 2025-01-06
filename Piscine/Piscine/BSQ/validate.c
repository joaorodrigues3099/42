/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:06:13 by joao-alm          #+#    #+#             */
/*   Updated: 2024/07/31 23:12:47 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	validate_unique_chars(t_map *map)
{
	int		i;
	int		j;
	char	unique_chars[3];

	unique_chars[0] = map->empty;
	unique_chars[1] = map->obstacle;
	unique_chars[2] = map->full;
	i = 0;
	while (i < 3)
	{
		j = i + 1;
		while (j < 3)
		{
			if (unique_chars[i] == unique_chars[j])
				map->valid = false;
			j++;
		}
		i++;
	}
}

void	validate_map_line(char *ptr, t_map *map)
{
	int	j;

	j = 0;
	while (j < map->cols)
	{
		if (ptr[j] != map->empty && ptr[j] != map->obstacle)
			map->valid = false;
		j++;
	}
}

void	get_fvalues(char *buffer, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map->rows = 0;
	while (buffer[i] >= '0' && buffer[i] <= '9')
	{
		map->rows *= 10;
		map->rows += buffer[i] - '0';
		i++;
	}
	while (buffer[i + j] != '\n')
		j++;
	if (j == 3)
	{
		map->empty = buffer[i];
		map->obstacle = buffer[i + 1];
		map->full = buffer[i + 2];
	}
	else
		map->valid = false;
}

void	validate_metadata(char *buffer, t_map *map)
{
	char	*ptr;
	int		cols;

	ptr = buffer;
	get_fvalues(ptr, map);
	validate_unique_chars(map);
	while (*ptr != '\n')
		ptr++;
	ptr++;
	if (*ptr <= 32)
		map->valid = false;
	cols = 0;
	while (ptr[cols] != '\n' && ptr[cols] != '\0')
		cols++;
	map->cols = cols;
	map->map = (char **)malloc(map->rows * sizeof(char *));
	if (!map->map)
		exit_with_error("Memory allocation error");
}
