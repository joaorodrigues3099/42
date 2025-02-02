/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:39:53 by dapetros          #+#    #+#             */
/*   Updated: 2024/03/16 18:41:23 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

# include "philo_bonus.h"

void	error_message(char *text, int signal);
void	destroy_all(t_engine *engine, char *str, bool isParentProc, int signal);
void	print_action(t_philo *philo, char *action);
size_t	get_current_time(void);
void	ft_usleep(size_t mls);
size_t	ft_strlen(const char *str);
long	ft_atoi(const char *str);

#endif   /* UTILS_BONUS_H */
