/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:04:34 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/21 12:04:34 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
#define SORT_H

#include "../libft/includes/listlib.h"

void	ft_sort_3(t_list **lst);
void	ft_sort_100(t_list **lst_a, t_list **lst_b, int **chunks, int n_chunks);

//utils
int		ft_node_in_range(t_list *node, int *range);
int		ft_lst_in_range(t_list *lst, int *range);
int		ft_max(t_list *lst);
int		ft_min(t_list *lst);
int		ft_get_value(t_list *lst, int pos);

#endif //SORT_H
