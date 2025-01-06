/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:37:43 by nacao             #+#    #+#             */
/*   Updated: 2024/07/23 07:41:24 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_display(int **grid, int size) //
{
	int	i; //line number
	int	j; //col number

	i = 0;
	while (i < size) //while reaches 4th line
	{
		j = 0;
		while (j < size) //while reaches 4th col
		{
			ft_putchar(grid[i][j] + 48); //writes number from solved grid
			if (j < size - 1) //checks if we reached the last digit of the line
				ft_putchar(' '); //if its not the last digit, give a space
			j++; //next digit
		}
		ft_putchar('\n'); //jump line
		i++;
	}
}
