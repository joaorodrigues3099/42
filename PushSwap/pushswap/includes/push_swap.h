/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:41:25 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/16 12:42:21 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include "../libft/includes/linklist.h"

//tab
int		*ft_get_tab(int ac, char **av, int *size);

//quartiles
int		**ft_get_quartiles(int *tab, int size);

//utils
void	ft_print_error(void);

//checks
int	ft_tab_sorted(int *tab, int size);
int	ft_tab_dups(int *tab, int size);

#endif //PUSH_SWAP_H
