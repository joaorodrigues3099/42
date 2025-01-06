/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:19:11 by joao-alm          #+#    #+#             */
/*   Updated: 2024/12/27 11:19:11 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "pushswap.h"

void	ft_error(t_ps *data);
void	ft_call_op(t_ps *data, const char *op);
void	ft_move_bot_a_to_top(t_ps *data);
int		ft_all_in_top_a(const t_ps *data);

#endif // CHECKER_BONUS_H
