/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_codes.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:07:42 by joao-alm          #+#    #+#             */
/*   Updated: 2025/01/21 14:40:01 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_CODES_H
# define ERROR_CODES_H

# define PINK "\033[38;2;231;133;190m"
# define RESET "\033[0m"

typedef struct s_game	t_game;

enum					e_error
{
	E_OK = 0,
	E_MEMORY_ALLOC = 12,
	E_INVALID_FD = 100,
	E_INVALID_FILE = 101,
	E_INVALID_TYPE = 102,
	E_INVALID_FORMAT = 103,
	E_SPRITES_MISSING = 104,
	E_MAP_NOT_RECTANGLE = 200,
	E_MAP_NOT_SURROUNDED = 201,
	E_MULTIPLE_STARTS = 202,
	E_MULTIPLE_EXITS = 203,
	E_INVALID_CHARACTER = 204,
	E_NO_START = 205,
	E_NO_EXIT = 206,
	E_NO_COLLECTIBLE = 207,
	E_OBSTRUCTED_PATH = 208
};

int						ft_print_error(int err_code);
void					ft_free_exit(t_game *game, int err_code);

#endif // ERROR_CODES_H
