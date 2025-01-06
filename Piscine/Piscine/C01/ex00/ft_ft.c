/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:07:22 by joao-alm          #+#    #+#             */
/*   Updated: 2024/07/14 09:51:40 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

int	main(void)
{
	int	a;
	int	*ptr;

	a = 10;
	ptr = &a;
	ft_ft(ptr);
	ft_putchar(48 + a / 10);
	ft_putchar(48 + a % 10);
	return (0);
}

