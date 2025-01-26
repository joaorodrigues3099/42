/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:14:44 by joao-alm          #+#    #+#             */
/*   Updated: 2025/01/15 19:14:44 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_codes.h"
#include "event.h"
#include <stdlib.h>

int	ft_handle_keys(const int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		ft_free_exit(game, EXIT_SUCCESS);
	}
	if (keycode == KEY_W || keycode == KEY_UP)
		ft_update_player_pos(game, 0, -1);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		ft_update_player_pos(game, -1, 0);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		ft_update_player_pos(game, 0, 1);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		ft_update_player_pos(game, 1, 0);
	return (0);
}

int	ft_press_x(t_game *game)
{
	ft_free_exit(game, EXIT_SUCCESS);
	return (0);
}
