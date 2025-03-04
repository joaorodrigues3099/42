/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:44:18 by joao-alm          #+#    #+#             */
/*   Updated: 2025/02/24 11:44:22 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * Calculates the length of the next line to be read from the file.
 *
 * @param file Linked list containing the file's contents.
 * @return The length of the next line,
 * including the newline character (if any).
 */
size_t	ft_line_len(t_list *file)
{
	size_t	line_len;
	size_t	i;
	char	*rest;

	line_len = 0;
	while (file && file->next)
	{
		line_len += BUFFER_SIZE;
		file = file->next;
	}
	i = 0;
	if (file)
	{
		rest = file->content;
		while (rest[i] && rest[i] != '\n')
			i++;
		if (rest[i] == '\n')
			i++;
	}
	return (line_len + i);
}

/**
 * Retrieves the next line from the file and stores it in the provided buffer.
 *
 * @param file Linked list containing the file's contents.
 * @param line Buffer to store the retrieved line.
 */
void	ft_get_line(t_list **file, char *line)
{
	size_t	i;
	size_t	j;
	char	*rest;

	j = 0;
	while (*file)
	{
		rest = (*file)->content;
		i = 0;
		while (rest[i] && rest[i] != '\n')
			line[j++] = rest[i++];
		if (rest[i] == '\n')
		{
			line[j++] = rest[i];
			break ;
		}
		ft_lstdel_safely(file, *file, free);
	}
	line[j] = '\0';
}

/**
 * Updates the buffer after reading a line, retaining any remaining content.
 *
 * @param file Linked list containing the file's contents.
 * @return 0 on success, -1 on error.
 */
int	ft_update_buffer(t_list **file)
{
	char	*old_file;
	char	*new_file;
	size_t	stay;
	size_t	len;

	old_file = (*file)->content;
	len = 0;
	while (old_file[len] && old_file[len] != '\n')
		len++;
	if (!old_file[len])
		return (ft_lstdel_safely(file, *file, free), 0);
	len++;
	stay = 0;
	while (old_file[len + stay])
		stay++;
	new_file = malloc(stay + 1);
	if (!new_file)
		return (-1);
	stay = 0;
	while (old_file[len])
		new_file[stay++] = old_file[len++];
	new_file[stay] = '\0';
	free((*file)->content);
	(*file)->content = new_file;
	return (0);
}

/**
 * Reads data from the file descriptor and stores it in a linked list.
 *
 * @param file Linked list to store the read content.
 * @param fd File descriptor from which data is read.
 * @return 0 on success, -1 on error.
 */
int	ft_read_file(t_list **file, const int fd)
{
	char	*temp;
	ssize_t	bytes_read;
	t_list	*new_node;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		temp = malloc(BUFFER_SIZE + 1);
		if (!temp)
			return (-1);
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(temp), -1);
		temp[bytes_read] = '\0';
		if (bytes_read == 0)
			return (free(temp), 0);
		new_node = ft_lstnew(temp);
		if (!new_node)
			return (free(temp), -1);
		ft_lstadd_back(file, new_node);
		if (ft_strchr(temp, '\n'))
			break ;
	}
	return (0);
}

/**
 * Reads a line from the file descriptor, handling multiple buffers.
 *
 * @param fd File descriptor to read from.
 * @return The next line from the file or NULL if there is no more data.
 */
char	*get_next_line(int fd)
{
	static t_list	*file[1025];
	char			*line;
	size_t			len;

	if (fd < 0 || fd > 1024)
		return (ft_lstclear(&file[fd], free), NULL);
	if (!file[fd] || (file[fd] && !ft_strchr(file[fd]->content, '\n')))
		if (ft_read_file(&file[fd], fd) != 0)
			return (ft_lstclear(&file[fd], free), NULL);
	len = ft_line_len(file[fd]);
	if (len == 0)
		return (ft_lstclear(&file[fd], free), NULL);
	line = malloc(len + 1);
	if (!line)
		return (ft_lstclear(&file[fd], free), NULL);
	ft_get_line(&file[fd], line);
	if (file[fd] && ft_update_buffer(&file[fd]) != 0)
		return (ft_lstclear(&file[fd], free), NULL);
	return (line);
}
