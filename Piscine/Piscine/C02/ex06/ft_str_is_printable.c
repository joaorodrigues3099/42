/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:12:19 by joao-alm          #+#    #+#             */
/*   Updated: 2024/07/18 16:40:23 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_printable(char *str)
{
	int	i;
	int	boolean;

	i = 0;
	boolean = 1;
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 127)
			boolean = 0;
		i++;
	}
	return (boolean);
}
/*
int	main(void)
{
	char	*str;
	int		bool;

	str = "ahsf009009U0898";
	bool = 48 + ft_str_is_printable(str);
	write(1, &bool, 1);
}
*/