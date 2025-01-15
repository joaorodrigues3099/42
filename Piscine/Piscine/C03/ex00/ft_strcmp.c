/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:14:56 by joao-alm          #+#    #+#             */
/*   Updated: 2024/07/18 16:05:26 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}
/*
int	main(void)
{
	char	*s1;
	char	*s2;

	s1 = "banana";
	s2 = "banana";
	#include <stdio.h>
	printf("String 1: %s\n", s1);
	printf("String 2: %s\n", s2);
	printf("stringcmp: %d", ft_strcmp(s1, s2));
}
*/