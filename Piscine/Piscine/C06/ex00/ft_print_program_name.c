/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:29:39 by joao-alm          #+#    #+#             */
/*   Updated: 2024/07/24 21:04:55 by joao-alm         ###   ########.fr       */
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
	if (argc == 1)
	{
		ft_strlen(argv[0]);
		ft_putchar('\n');
	}
	return (0);
}
