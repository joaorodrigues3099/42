/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:36:56 by joao-alm          #+#    #+#             */
/*   Updated: 2024/07/18 07:59:49 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_alpha(char *str)
{
	int		i;
	int		alpha;

	i = 0;
	alpha = 1;
	while (str[i] != '\0')
	{
		if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
		{
			alpha = 0;
		}
		i++;
	}
	return (alpha);
}
/*
int	main(void)
{
	char	*str;
	char	alpha;

	str = "abcdefghijklmnopqrstuvwxyz";
	alpha = (48 + ft_str_is_alpha(str));
	write(1, &alpha, 1);
	return (0);
}
*/