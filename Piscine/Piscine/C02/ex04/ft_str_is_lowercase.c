/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:27:57 by joao-alm          #+#    #+#             */
/*   Updated: 2024/07/18 08:02:45 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;
	int	lower;

	i = 0;
	lower = 1;
	while (str[i])
	{
		if (str[i] < 'a' || str[i] > 'z')
		{
			lower = 0;
		}
		i++;
	}
	return (lower);
}
/*
int	main(void)
{
	char	*str;
	int		bool;

	str = "abcSde";
	bool = 48 + ft_str_is_lowercase(str);
	write(1, &bool, 1);
}
*/