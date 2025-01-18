/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:04:53 by joao-alm          #+#    #+#             */
/*   Updated: 2025/01/18 17:04:53 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lib_string.h>
#include <stdlib.h>
#include "map.h"

char	**duplicate_map(char **map)
{
	int i = -1;
	int rows = 0;
	char **copy;

	rows = 0;
	while (map[rows])
		rows++;
	copy = (char **)malloc((rows + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	while (++i < rows)
		copy[i] = ft_strdup(map[i]);
	copy[i] = NULL;
	return (copy);
}
