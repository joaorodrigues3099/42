/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:33:58 by joao-alm          #+#    #+#             */
/*   Updated: 2025/01/15 18:15:59 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lib_print.h>
#include <stddef.h>

#include "error_codes.h"
#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_print_error(E_INVALID_FORMAT));
	ft_handle_map(&game.map, av[1]);
	ft_printf("Valid map!\n");
	ft_window(&game);
	return (0);
}
