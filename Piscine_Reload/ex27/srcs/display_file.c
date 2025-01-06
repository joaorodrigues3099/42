/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 08:13:37 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/15 08:55:12 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int	return_print_error(char *error)
{
	while (*error)
		write(2, error++, 1);
	return (1);
}

int	ft_display_file(const char *filename)
{
	int		fd;
	char	buffer[BUFFER_SIZE];
	size_t	bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (fd);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		write(1, buffer, bytes_read);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	close(fd);
	return (1);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (return_print_error("File name missing.\n"));
	if (ac > 2)
		return (return_print_error("Too many arguments.\n"));
	if (ft_display_file(av[1]) < 0)
		return (return_print_error("Cannot read file.\n"));
	return (0);
}
