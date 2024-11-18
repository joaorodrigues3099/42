/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:12:07 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/18 09:12:07 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../libft/includes/linklist.h"
#include <stdlib.h>

void	ft_del(void *ptr)
{
	free(ptr);
}

t_list	*ft_lstnew_int(int i)
{
	int	*ptr;

	ptr = (int *)malloc(1 * sizeof(int));
	if (!ptr)
		return (NULL);
	*ptr = i;
	return (ft_lstnew(ptr));
}
