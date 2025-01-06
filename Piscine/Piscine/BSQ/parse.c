/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:21:19 by ctirapo-          #+#    #+#             */
/*   Updated: 2024/07/31 23:17:50 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	parse_map_lines(char *ptr, t_map *map)
{
	int	i;
	int	line_length;

	while (*ptr != '\n')
		ptr++;
	ptr++;
	i = 0;
	while (i < map->rows)
	{
		line_length = 0;
		while (ptr[line_length] != '\n' && ptr[line_length] != '\0')
			line_length++;
		if (line_length != map->cols)
			map->valid = false;
		validate_map_line(ptr, map);
		map->map[i] = ft_strdup(ptr, map->cols);
		ptr += line_length;
		if (*ptr == '\n')
			ptr++;
		i++;
	}
}

long	ft_file_size(const char *filename)
{
	long	file_size;
	char	c;
	int		fd;

	file_size = 0;
	fd = open(filename, O_RDONLY);
	while (read(fd, &c, 1) > 0)
		file_size++;
	close(fd);
	return (file_size);
}

char	*read_file(const char *filename, long file_size)
{
	int		fd;
	long	size;
	ssize_t	bytes_read;
	char	*buffer;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_with_error("Error opening file");
	size = file_size;
	if (size == -1)
		exit_with_error("Error determining file size");
	buffer = (char *)malloc(size + 1);
	if (!buffer)
		exit_with_error("Memory allocation error");
	bytes_read = read(fd, buffer, size);
	if (bytes_read != size)
		exit_with_error("Error reading file");
	buffer[file_size] = '\0';
	close(fd);
	return (buffer);
}

char	*read_stdi(size_t buffer_size)
{
	char	buffer[BUFFER_SIZE];
	char	*result;
	ssize_t	bytes_read;
	size_t	result_size;

	result = NULL;
	result_size = 0;
	result = (char *)malloc(buffer_size);
	if (!result)
		exit_with_error("Memory allocation error");
	bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		if (result_size + bytes_read >= buffer_size)
		{
			buffer_size *= 2;
			result = grow_buffer(result, &buffer_size, &result_size);
		}
		my_memcpy(result + result_size, buffer, bytes_read);
		result_size += bytes_read;
		bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
	}
	result[result_size] = '\0';
	return (result);
}

t_map	parse_file(const char *filename, bool stdi)
{
	t_map	map;
	long	file_size;
	char	*buffer;

	map.valid = true;
	file_size = ft_file_size(filename);
	if (stdi)
		buffer = read_stdi(BUFFER_SIZE);
	else
		buffer = read_file(filename, file_size);
	validate_metadata(buffer, &map);
	parse_map_lines(buffer, &map);
	free(buffer);
	return (map);
}
