/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 06:57:25 by joao-alm          #+#    #+#             */
/*   Updated: 2024/12/10 06:57:25 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "lib_list.h"

t_list	*ft_lstnew_int(int i)
{
	return (ft_lstnew((void *)(intptr_t)i));
}
