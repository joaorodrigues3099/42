/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstget_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 06:58:58 by joao-alm          #+#    #+#             */
/*   Updated: 2024/12/10 06:58:58 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "lib_list.h"

int	ft_lstget_int(const t_list *lst)
{
	return ((int)(intptr_t)lst->content);
}
