/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:37:59 by nacao             #+#    #+#             */
/*   Updated: 2024/07/22 09:56:00 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str) //counts the string's lenght
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_grid_size(char *str) //checks if the size of the argument is valid, allows for 4x4, 5x5 and 6x6 grids
{
	int	i;

	i = 4;
	while (i <= 6)
	{
		if (ft_strlen(str) == (i * 4 * 2 - 1)) //ft_strlen
			return (i);
		i++;
	}
	return (0);
}

int	**ft_alloc_clues(int **clues, int size)
{
	int	i;

	clues = (int **)malloc(sizeof(int *) * 4); //allocates memory for 4 int pointers
	if (!clues)
		return (0); //if no memory available
	i = 0;
	while (i < 4) //allocates 4 memory 
	{
		clues[i] = (int *)malloc(sizeof(int) * size); //allocates memory = size for every array of clues (pointer)
		if (!clues[i])
			return (0); //if no memory return 0
		i++;
	}
	return (clues); //return clues
}

int	**ft_set_clues(char *str, int **clues, int size)
{
	int	i;	//lopp variables
	int	j;	

	i = 0; //goes through string
	j = 0; //counts clues
	while (str[i]) //while string is different than '\0'
	{
		if (!(str[i] >= '0' && str[i] <= '9')) //check if value sis between 0 and 9
			return (0); //return 0 if there is not. This string is not correctly inputed!
		else
		{
			clues[(i - j) / size][(i - j) % size] = str[i] - 48; //allocates the clues in the clues array previously reserved (malloc)
			i++;
			if (str[i] != ' ' && str[i] != '\0') //return 0 if the character after the number is neither a space or null. String is not correct!
				return (0);
			else
			{
				if (str[i]) //if string is different than '\0' go to next number
					i++;
				j++;
			}
		}
	}
	return (clues); //return filled clues array
}

int	**ft_input(char *str)
{
	int	**clues;
	int	size;

	size = ft_grid_size(str); //counts size again
	clues = 0;
	if (size)
	{
		clues = ft_alloc_clues(clues, size); //ft_alloc_clues
		clues = ft_set_clues(str, clues, size); //ft_set:clues
		return (clues); //return filled clues array
	}
	else
		return (0); //if size is null return 0
}
