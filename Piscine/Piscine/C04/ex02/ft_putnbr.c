/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 20:05:45 by joao-alm          #+#    #+#             */
/*   Updated: 2024/07/24 12:10:52 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_nbr_to_arr(int nbr, char arr[12])
{
	int	i;

	i = 0;
	if (nbr == 2147483647 || nbr == -2147483648)
	{
		if (nbr == 2147483647)
			write(1, "2147483647", 10);
		if (nbr == -2147483648)
			write(1, "-2147483648", 11);
		return (0);
	}
	while ((nbr / 10) > 0)
	{
		arr[i] = ('0' + (nbr % 10));
		nbr /= 10;
		i++;
	}
	if (nbr < 10)
	{
		arr[i] = (48 + nbr);
		i++;
	}
	return (i);
}

void	ft_putnbr(int nbr)
{
	char	arr[12];
	int		i;
	int		j;

	if (nbr < 0 && nbr != -2147483648)
	{
		nbr = -nbr;
		ft_putchar('-');
	}
	i = ft_nbr_to_arr(nbr, arr);
	j = 0;
	while (j != i)
	{
		ft_putchar(arr[i - j - 1]);
		j++;
	}
}
/*
int	main(void)
{
	ft_putnbr(-321783);
	return (0);
}
*/