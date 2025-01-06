/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:37:29 by joao-alm          #+#    #+#             */
/*   Updated: 2024/07/18 08:16:18 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strupcase(char *str)
{
	int		i;
	char	j;
	char	k;

	i = 0;
	while (str[i])
	{
		j = str[i];
		if (j >= 'a' && j <= 'z')
		{
			k = j - 32;
			str[i] = k;
		}
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	char	str[] = "aBc634643634DeFgH";
	char	*test;

	test = ft_strupcase(str);
	write(1, &str, 8);
}
*/