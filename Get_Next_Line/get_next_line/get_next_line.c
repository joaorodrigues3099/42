/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <support@toujoustudios.net>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:41:40 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/05 15:41:40 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

/**
 * Joins two strings, frees the first one, and returns the result.
 *
 * @param s1 First string
 * @param s2 Second string
 * @return A new string containing s1 + s2
 */
char	*ft_join_free(char *s1, char *s2)
{
	char	*temp_buffer;

	temp_buffer = ft_strjoin(s1, s2);
	free(s1);
	return (temp_buffer);
}

/**
 * Fills a line from the buffer up to and including the newline.
 *
 * @param buffer Input buffer
 * @return A newly allocated string containing the line
 */
char	*ft_fill_line(const char *buffer)
{
	char	*line;
	size_t	line_len;
	size_t	i;

	line_len = 0;
	while (buffer[line_len] && buffer[line_len] != '\n')
		line_len++;
	if (buffer[line_len] == '\n')
		line_len++;
	line = (char *)malloc(line_len + 1);
	if (!line)
		return (NULL);
	i = -1;
	while (++i < line_len)
		line[i] = buffer[i];
	line[i] = '\0';
	return (line);
}

/**
 * Updates the buffer by removing the portion already read.
 *
 * @param buffer Original buffer
 * @param line Line read from the buffer
 * @return A new buffer without the content of line
 */
char	*ft_update_buffer(char *buffer, const char *line)
{
	size_t	buffer_len;
	size_t	line_len;
	ssize_t	i;
	char	*new_buffer;

	buffer_len = ft_strlen(buffer);
	line_len = ft_strlen(line);
	if (buffer_len == line_len)
		return (free(buffer), NULL);
	new_buffer = (char *)malloc(buffer_len - line_len + 1);
	if (!new_buffer)
		return (free(buffer), NULL);
	i = -1;
	while (buffer[line_len + ++i])
		new_buffer[i] = buffer[line_len + i];
	new_buffer[i] = '\0';
	free(buffer);
	return (new_buffer);
}

/**
 * Reads from the file descriptor into the buffer until a newline is found.
 *
 * @param fd File descriptor
 * @param buffer Buffer to read into
 * @return The updated buffer with data read from fd
 */
char	*ft_fill_buffer(int fd, char *buffer)
{
	char	*temp_buffer;
	ssize_t	bytes_read;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	if (!buffer)
		return (NULL);
	temp_buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!temp_buffer)
		return (free(buffer), NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), free(temp_buffer), NULL);
		temp_buffer[bytes_read] = '\0';
		buffer = ft_join_free(buffer, temp_buffer);
		if (!buffer)
			return (free(temp_buffer), NULL);
		if (ft_strchr(temp_buffer, '\n'))
			break ;
	}
	return (free(temp_buffer), buffer);
}

/**
 * Retrieves the next line from a file descriptor.
 *
 * @param fd File descriptor
 * @return The next line read from the file descriptor
 */
char	*get_next_line(int fd)
{
	static char	*static_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static_buffer = ft_fill_buffer(fd, static_buffer);
	if (!static_buffer)
		return (NULL);
	line = ft_fill_line(static_buffer);
	if (!line || !(line[0]))
	{
		free(static_buffer);
		static_buffer = NULL;
		return (free(line), NULL);
	}
	static_buffer = ft_update_buffer(static_buffer, line);
	return (line);
}
