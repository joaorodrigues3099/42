/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 19:49:29 by joao-alm          #+#    #+#             */
/*   Updated: 2024/07/24 09:48:53 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	number;

	i = 0;
	sign = 1;
	number = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (number * sign);
}

int	is_valid(char *str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (i < 2)
		return (0);
	j = 0;
	k = 0;
	while (str[j] != '\0')
	{
		k = j + 1;
		while (str[k] < i)
		{
			if (str[k] == str[j])
				return (0);
			k++;
		}
		if (str[j] == '-' || str[j] == '+')
			return (0);
		j++;
	}
	return (1);
}

int	ft_out(int input, int len, char *base)
{
	char	buffer[32];
	int		i;
	long	nbr;

	i = 0;
	while (input > 0)
	{
		buffer[i] = base[input % len];
		input /= len;
		i++;
	}
	nbr = 0;
	while (i > 0)
	{
		i--;
		nbr = nbr * 10;
		nbr = nbr + buffer[i] - '0';
	}
	return (nbr);
}

int	ft_atoi_base(char *str, char *base)
{
	int	atoi;
	int	sign;
	int	nbr;
	int	len;

	if (!is_valid(base))
		return (0);
	atoi = ft_atoi(str);
	sign = 1;
	if (atoi == 0)
		return (0);
	if (atoi < 0)
	{
		sign *= -1;
		atoi *= -1;
	}
	len = ft_strlen(base);
	nbr = ft_out(atoi, len, base);
	return (nbr * sign);
}
/*
int	main(int argc, char **argv)
{
	if (argc == 3)
		printf("ft_atoi_base return: %d\n", ft_atoi_base(argv[1], argv[2]));
	return (0);
}
*/