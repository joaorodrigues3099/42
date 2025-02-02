/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:39:33 by dapetros          #+#    #+#             */
/*   Updated: 2024/03/16 18:40:19 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_BONUS_H
# define INIT_BONUS_H

# include "philo_bonus.h"

void		init_philos(t_engine *engine, char **argv, int count);
void		init_sems(t_engine *engine, t_sems *sems, int count);
t_engine	*init_engine(int count);

#endif   /* INIT_BONUS_H */
