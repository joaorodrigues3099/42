/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:46:50 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/14 20:05:19 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char *))
{
	int	count;

	count = 0;
	while (*tab)
	{
		if ((*f)(*(tab++)) == 1)
			count++;
	}
	return (count);
}
/*
int	ft_is_numeric(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

#includes <stdio.h>
#includes <stdlib.h>

int	main(int ac, char **av)
{
	char	**tab;
	int		i;

	if (ac < 2)
		return (1);
	tab = (char **)malloc(ac * sizeof(char *));
	i = 1;
	while (i < ac)
	{
		tab[i - 1] = av[i];
		i++;
	}
	tab[i - 1] = 0;
	printf("ft_count: %d\n", ft_count_if(tab, &ft_is_numeric));
	return (0);
}
*/