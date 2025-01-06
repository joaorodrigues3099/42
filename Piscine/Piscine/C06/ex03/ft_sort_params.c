/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:47:25 by joao-alm          #+#    #+#             */
/*   Updated: 2024/07/24 21:05:23 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_count(char *str)
{
	int	i;

	i = 0;
	while (*str++ != '\0')
		i++;
	return (i);
}

void	ft_swap(char **mat1, char **mat2)
{
	char	*a;

	a = *mat1;
	*mat1 = *mat2;
	*mat2 = a;
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_sorter(char **strar, int size)
{
	int		i;
	int		j;

	i = 1;
	j = 1;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_strcmp(strar[i], strar[j]) > 0)
				ft_swap(&strar[i], &strar[j]);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	char	c;

	i = 1;
	c = '\n';
	ft_sorter(argv, argc);
	while (i < argc)
	{
		write(1, argv[i], ft_count(argv[i]));
		write(1, &c, 1);
		i++;
	}
	return (0);
}
