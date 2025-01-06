/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 19:27:15 by joao-alm          #+#    #+#             */
/*   Updated: 2024/07/24 08:19:09 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_count(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	is_valid(char *str, int size)
{
	int	i;
	int	j;

	if (size < 2)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		j = i + 1;
		while (j < size)
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		if (str[i] == '-' || str[i] == '+')
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nb;
	char	buffer[32];
	int		i;

	if (!is_valid(base, ft_count(base)))
		return ;
	nb = nbr;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb == 0)
	{
		ft_putchar(base[0]);
		return ;
	}
	i = 0;
	while (nb > 0)
	{
		buffer[i++] = base[nb % ft_count(base)];
		nb /= ft_count(base);
	}
	while (i > 0)
		ft_putchar(buffer[--i]);
}
/*
int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_putnbr_base(atoi(argv[1]), argv[2]);
	else
		write(1, "No Args\n", 7);
*/