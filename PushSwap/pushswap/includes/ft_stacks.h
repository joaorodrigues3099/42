/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <support@toujoustudios.net>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:03:13 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/09 18:03:13 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
#define STACKS_H

typedef struct s_node
{
	int position;
	int	value;
}				t_node;

void	ft_swap_content(void **ptr1, void **ptr2);

#endif //STACKS_H
