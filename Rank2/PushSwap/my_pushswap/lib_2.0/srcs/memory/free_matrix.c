/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix_pos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:06:31 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/16 13:06:31 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_memory.h"

/**
 * Frees the matrix lines from the given array to 0.\n
 * Afterward frees matrix pointer itself.
 *
 * @param matrix Matrix to free.
 * @param index Index to start freeing from.
 */
void	ft_free_matrix(void **matrix, int index)
{
	while (index >= 0)
		free(matrix[index--]);
	free(matrix);
}
