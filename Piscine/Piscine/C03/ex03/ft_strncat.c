/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:58:01 by joao-alm          #+#    #+#             */
/*   Updated: 2024/07/18 16:11:04 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	count;

	count = 0;
	while (dest[count])
		count++;
	i = 0;
	while (src[i] && i < nb)
	{
		dest[count] = src[i];
		i++;
		count++;
	}
	dest[count] = 0;
	return (dest);
}
/*
int	main(void)
{
	char	dest[] = "Hello ";
	char	src[] = "World!";
	printf("dest: %s\n", src);
	printf("src: %s\n", dest);
	printf("strcat: %s\n", ft_strncat(dest, src, 3));
	return (0);
}
*/