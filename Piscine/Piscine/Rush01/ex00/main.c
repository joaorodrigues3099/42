/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:32:31 by nacao             #+#    #+#             */
/*   Updated: 2024/07/22 09:55:53 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		**ft_input(char *str);
int		ft_is_height_not_there(int **grid, int tab[], int height);
int		ft_is_valid_left(int **grid, int clue, int tab[], int height);
int		ft_is_valid_right(int **grid, int clue, int tab[], int height);
int		ft_is_valid_top(int **grid, int clue, int tab[], int height);
int		ft_is_valid_bottom(int **grid, int clue, int tab[], int height);
int		ft_grid_size(char *str);
void	ft_display(int **grid, int size);
int		**ft_set_start_grid(int **grid, int size);
int		**ft_set_grid(int **grid, int size);

//for where to put
//int **grid -> 2d arrey/ size is for the grid
/*if (grid[row][col] == 0) //check for an empty cell
 res[0] = row;//store the row index of the empty cell
 res[1] = col;
 return (res);//return the coordinates of the frist empty cell fou
*/
int	*ft_find_empty_cell(int **grid, int size)
{
	int	row; 
	int	col;
	int	*res; 

	res = (int *)malloc(sizeof(int) * 2); //reserved space for 2 ints col and row
	if (!res)
		return (0); //if no available space, return 0
	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			if (grid[row][col] == 0) //return first empty cell that it encounters
			{
				res[0] = row;
				res[1] = col;
				return (res);
			}
			col++;
		}
		row++;
	}
	return (0);
}

//check if the grid is completely filled - no empty cells
int	ft_grid_is_complete(int **grid, int size)
{
	int	row;
	int	col;

	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			if (grid[row][col] == 0)
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}

//check if the number satisfies all the required conditions
int	ft_comb_is_valid(int **grid, int **clues, int tab[], int height) //combverif.c
{
	if (!ft_is_height_not_there(grid, tab, height)) //check duplicates
	{
		return (0);
	}
	if (!ft_is_valid_left(grid, clues[2][tab[0]], tab, height)) 
	{
		return (0);
	}
	if (!ft_is_valid_right(grid, clues[3][tab[0]], tab, height))
	{
		return (0);
	}
	if (!ft_is_valid_top(grid, clues[0][tab[1]], tab, height))
	{
		return (0);
	}
	if (!ft_is_valid_bottom(grid, clues[1][tab[1]], tab, height))
	{
		return (0);
	}
	return (1); //if it passes all validations, return 1
}

int	**ft_solver(int **grid, int **clues, int size)
{
	int	*zero_index;
	int	i;
	int	tab[3];

	if (ft_grid_is_complete(grid, size))
	{
		return (grid);
	}
	zero_index = ft_find_empty_cell(grid, size); //find empty cell
	tab[0] = zero_index[0]; //gives row coordinate to array
	tab[1] = zero_index[1]; //gives col coordinate to array
	tab[2] = size; //gives size to the array
	i = 1;
	while (i <= size)
	{
		if (ft_comb_is_valid(grid, clues, tab, i)) //ft_comb_is_valid
		{
			grid[zero_index[0]][zero_index[1]] = i; //put the number in the previously checked row and col
			if (ft_solver(grid, clues, size)) //recursive calls the own function
				return (grid); //retun solved grid
			grid[zero_index[0]][zero_index[1]] = 0;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	**grid;
	int	**clues;
	int	size;

	if (argc == 2) //check if there's just one inputed argument
	{
		size = ft_grid_size(argv[1]); //input.c 
		clues = ft_input(argv[1]); //input.c
		grid = 0;
		grid = ft_set_grid(grid, size); //others.c
		grid = ft_set_start_grid(grid, size); //other.c
		if (clues) //if there is valid clues
			grid = ft_solver(grid, clues, size); //ft_solver
		if (!grid || !clues)
			write(1, &"Error\n", 6);
		else
			ft_display(grid, size);
	}
	else
		write(1, &"Error\n", 6);
}
