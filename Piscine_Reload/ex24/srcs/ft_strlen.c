/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:28:16 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/14 16:32:15 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
/*
#includes <stdio.h>

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	printf("strlen: %d\n", ft_strlen(av[1]));
	return (0);
}
*/