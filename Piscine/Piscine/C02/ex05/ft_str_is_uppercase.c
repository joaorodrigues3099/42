/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:58:30 by joao-alm          #+#    #+#             */
/*   Updated: 2024/07/18 08:03:59 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;
	int	upper;

	i = 0;
	upper = 1;
	while (str[i])
	{
		if (str[i] < 'A' || str[i] > 'Z')
		{
			upper = 0;
		}
		i++;
	}
	return (upper);
}
/*
int	main(void)
{
	char	*str;
	char	bool;

	str = "GJHFDHD";
	bool = 48 + ft_str_is_uppercase(str);
	write(1, &bool, 1);
	return (0);
}
*/