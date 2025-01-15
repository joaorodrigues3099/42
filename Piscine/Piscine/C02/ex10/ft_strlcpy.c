/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 21:49:55 by joao-alm          #+#    #+#             */
/*   Updated: 2024/07/22 10:16:29 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	count;

	count = 0;
	while (src[count] != '\0')
		count++;
	i = 0;
	if (size > 0)
	{
		while (i < (size - 1) && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (count);
}

/*
int	main(void)
{
	char	src[] = "123456789";
	char	dest[0];
	int		count;

	#include <stdio.h>
	printf ("src: %s\n", src);
	printf ("dest before: %s\n", dest);
	count = ft_strlcpy (dest, src, 20);
	printf ("dest after: %s\n", dest);
	printf ("count: %d", count);
}
*/