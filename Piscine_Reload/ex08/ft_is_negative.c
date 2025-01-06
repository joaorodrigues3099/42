/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:16:49 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/14 11:22:10 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_is_negative(int n)
{
	if (n < 0)
		ft_putchar('N');
	else
		ft_putchar('P');
}
/*
#includes <stdlib.h>

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	ft_is_negative(atoi(av[1]));
	ft_putchar('\n');
	return (0);
}
*/