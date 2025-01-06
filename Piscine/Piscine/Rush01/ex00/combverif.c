/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combverif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:12:27 by nacao             #+#    #+#             */
/*   Updated: 2024/07/22 09:55:54 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//non repetive
//tab[0] for row, tab[1] for column, tab[2] for grid size
//int c -> counter, how many times we find this letter
//tab[2] -> 16 /ensure i is inside the grid
int	ft_is_height_not_there(int **grid, int tab[], int height) //checks if the value inputed is already in same row or col
{
	int	c;
	int	i;

	c = 0;
	i = 0;
	while (i < tab[2])
	{
		if (grid[i][tab[1]] == height || grid[tab[0]][i] == height)
			c++;
		i++;
	}
	if (c > 0)
		return (0);
	else
		return (1);
}

//clue -> from left to right, the number of the tallest boxesclue
//height -> the height of the box to be placed
//int c -> the count of the highest boxes seen
//int highest -> the current highest boxes seen
int	ft_is_valid_left(int **grid, int clue, int tab[], int height)
{
	int	c;
	int	hightest;
	int	i;

	grid[tab[0]][tab[1]] = height;
	hightest = 0;
	c = 0;
	i = 0;
	while (i <= tab[1])
	{
		if (grid[tab[0]][i] > hightest)
		{
			hightest = grid[tab[0]][i];
			c++; //count height
		}
		i++;
	}
	grid[tab[0]][tab[1]] = 0;
	if ((tab[1] == tab[2] - 1 && c != clue) //compares height of current block with clue
		|| (tab[1] != tab[2] - 1 && c > clue))
		return (0);
	else if ((tab[1] == tab[2] - 1 && c == clue)
		|| (tab[1] != tab[2] - 1 && c <= clue))
		return (1);
	return (0);
}

//(grid[tab[0]][i] > hightest)
//the current col is greater than the current highest box seen
int	ft_is_valid_right(int **grid, int clue, int tab[], int height)
{
	int	c;
	int	hightest;
	int	i;

	if (tab[1] != tab[2] - 1)
		return (1);
	grid[tab[0]][tab[1]] = height;
	hightest = 0;
	c = 0;
	i = tab[2] - 1;
	while (i >= 0)
	{
		if (grid[tab[0]][i] > hightest)
		{
			hightest = grid[tab[0]][i];
			c++;
		}
		i--;
	}
	grid[tab[0]][tab[1]] = 0;
	if (tab[1] == tab[2] - 1 && c != clue)
		return (0);
	else if (tab[1] == tab[2] - 1 && c == clue)
		return (1);
	return (0);
}

int	ft_is_valid_top(int **grid, int clue, int tab[], int height)
{
	int	c;
	int	hightest;
	int	i;

	grid[tab[0]][tab[1]] = height;
	hightest = 0;
	c = 0;
	i = 0;
	while (i <= tab[0])
	{
		if (grid[i][tab[1]] > hightest)
		{
			hightest = grid[i][tab[1]];
			c++;
		}
		i++;
	}
	grid[tab[0]][tab[1]] = 0;
	if ((tab[0] == tab[2] - 1 && c != clue)
		|| (tab[1] != tab[2] - 1 && c > clue))
		return (0);
	else if ((tab[0] == tab[2] - 1 && c == clue)
		|| (tab[0] != tab[2] - 1 && c <= clue))
		return (1);
	return (0);
}

int	ft_is_valid_bottom(int **grid, int clue, int tab[], int height)
{
	int	c;
	int	hightest;
	int	i;

	if (tab[0] != tab[2] - 1)
		return (1);
	grid[tab[0]][tab[1]] = height;
	hightest = 0;
	c = 0;
	i = tab[2] - 1;
	while (i >= 0)
	{
		if (grid[i][tab[1]] > hightest)
		{
			hightest = grid[i][tab[1]];
			c++;
		}
		i--;
	}
	grid[tab[0]][tab[1]] = 0;
	if (tab[0] == tab[2] - 1 && c != clue)
		return (0);
	else if (tab[0] == tab[2] - 1 && c == clue)
		return (1);
	return (0);
}
