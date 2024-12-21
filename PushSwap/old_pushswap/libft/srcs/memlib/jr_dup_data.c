/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 22:25:50 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/25 22:25:50 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/memlib.h"
#include "../../includes/strlib.h"
#include <stdlib.h>

void	*ft_dup_data(void *data, int type)
{
	void *dup;

	dup = NULL;
	if (type == 0)
	{
		dup = malloc(sizeof(int));
		if (dup)
			*(int *)dup = *(int *)data;
	}
	else if (type == 1)
		dup = ft_strdup((char *)data);
	return (dup);
}