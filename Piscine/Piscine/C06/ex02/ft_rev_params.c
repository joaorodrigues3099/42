/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:52:05 by joao-alm          #+#    #+#             */
/*   Updated: 2024/07/24 18:04:11 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
		ft_putchar(*str++);
}

int	main(int argc, char **argv)
{
	int	i;

	i = argc -1;
	while (i > 0)
	{
		ft_strlen(argv[i]);
		ft_putchar('\n');
		i--;
	}
	return (0);
}
