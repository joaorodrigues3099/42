/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:48:57 by joao-alm          #+#    #+#             */
/*   Updated: 2024/07/18 16:34:22 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[j] == 0)
		return (str);
	while (str[i])
	{
		while (str[i + j] == to_find[j] && str[i + j])
			j ++;
		if (to_find[j] == 0)
			return (str + i);
		i++;
		j = 0;
	}
	return (0);
}
/*
int	main(void)
{
	char	src[] = "Hello World!";
	char	to_find[] = "llo";
	printf("dest: %s\n", src);
	printf("src: %s\n", to_find);
	printf("strcat: %s\n", ft_strstr(src, to_find));
	return (0);
}
*/