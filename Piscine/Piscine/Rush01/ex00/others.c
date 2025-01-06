/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:38:16 by nacao             #+#    #+#             */
/*   Updated: 2024/07/22 09:55:56 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_grid_size(char *str);

int	**ft_set_start_grid(int **grid, int size) //creates empty grid
{
	int	row;
	int	col;

	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			grid[row][col] = 0;
			col++;
		}
		row++;
	}
	return (grid);
}

int	**ft_set_grid(int **grid, int size) 
{
	int	row;

	grid = (int **)malloc(sizeof(int *) * size); //same as we did for the clues, this time for the grid
	if (!grid)
		return (0);
	row = 0;
	while (row < size)
	{
		grid[row] = (int *)malloc(sizeof(int) * size);
		if (!grid[row])
			return (0);
		row++;
	}
	return (grid);
}
