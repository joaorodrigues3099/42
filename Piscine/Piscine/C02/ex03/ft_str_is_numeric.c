/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:15:35 by joao-alm          #+#    #+#             */
/*   Updated: 2024/07/18 08:01:22 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_numeric(char *str)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 1;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			nbr = 0;
		}
		i++;
	}
	return (nbr);
}
/*
int	main(void)
{
	char	*str;
	char	nbr;

	str = "12a34";
	nbr = 48 + ft_str_is_numeric(str);
	write(1, &nbr, 1);
}
*/