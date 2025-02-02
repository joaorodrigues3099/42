/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:39:46 by dapetros          #+#    #+#             */
/*   Updated: 2024/03/16 18:41:00 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_BONUS_H
# define SIMULATION_BONUS_H

# include "philo_bonus.h"

void	*die_checker(void *ptr);
void	*meal_checker(void *ptr);
void	philo_routine(t_philo *philo);
void	start_simulation(t_philo *philo);
void	launcher(t_engine *engine, int count);

#endif   /* SIMULATION_BONUS_H */
