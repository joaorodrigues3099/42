/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:01:30 by joao-alm          #+#    #+#             */
/*   Updated: 2025/01/14 15:35:57 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "error_codes.h"

/**
 * Writes a String on the given file descriptor.
 *
 * @param s String to write.
 * @param fd File Descriptor to write on.
 */
static void	ft_puterr(char *s)
{
	if (!s)
		return ;
	while (*s)
		write(1, s++, 1);
}

int	ft_print_error(const int err_code)
{
	if (err_code == E_OK)
		return (0);
    ft_puterr("Error\n");
    ft_puterr(PINK );
	if (err_code == E_INVALID_FD)
		ft_puterr("Invalid fd\n");
	else if (err_code == E_MEMORY_ALLOC)
		ft_puterr("Memory allocation failed\n");
	else if (err_code == E_INVALID_FILE)
		ft_puterr("Invalid map file\n");
	else if (err_code == E_INVALID_TYPE)
		ft_puterr("Invalid map file type\n");
	else if (err_code == E_INVALID_FORMAT)
		ft_puterr("Format: ./so_long <MAP FILE PATH>\n");
	else if (err_code == E_MAP_NOT_RECTANGLE)
		ft_puterr("Map is not rectangle\n");
	else if (err_code == E_MAP_NOT_SURROUNDED)
		ft_puterr("Map is not surrounded by walls\n");
	else if (err_code == E_INVALID_CHARACTER)
		ft_puterr("Invalid Character. Only ('0', '1', 'P', 'C', 'E') allowed\n");
	else if (err_code == E_MULTIPLE_STARTS)
		ft_puterr("Only one player start ('P') allowed\n");
	else if (err_code == E_MULTIPLE_EXITS)
		ft_puterr("Only one exit ('E') allowed\n");
	else if (err_code == E_NO_START)
		ft_puterr("One player start ('P') is required\n");
	else if (err_code == E_NO_EXIT)
		ft_puterr("One exit ('E') is required\n");
	else if (err_code == E_NO_COLLECTIBLE)
		ft_puterr("At least one collectible ('C') is required\n");
	else if (err_code == E_OBSTRUCTED_PATH)
		ft_puterr("Path to exit/object is obstructed\n");
    ft_puterr(RESET);
	return (err_code);
}
