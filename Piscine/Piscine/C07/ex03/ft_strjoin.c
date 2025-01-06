/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:58:49 by joao-alm          #+#    #+#             */
/*   Updated: 2024/07/25 14:42:33 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *s1, char *s2)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(s1);
	while (s2[j] != '\0')
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}

int	ft_alloc(int size, char **strs, char *sep)
{
	int	i;
	int	str;

	i = 0;
	str = 0;
	while (i < size)
		str += ft_strlen(strs[i++]);
	str += (size - 1) * ft_strlen(sep);
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*strjoin;
	int		sizejoin;
	int		i;

	if (size == 0)
	{
		strjoin = (char *)malloc(1);
		if (strjoin)
			strjoin[0] = '\0';
		return (strjoin);
	}
	sizejoin = ft_alloc(size, strs, sep);
	strjoin = (char *)malloc(sizejoin + 1);
	if (!strjoin)
		return (NULL);
	i = 0;
	strjoin[0] = '\0';
	while (i < size)
	{
		strjoin = ft_strcat(strjoin, strs[i]);
		if (i < size - 1)
			strjoin = ft_strcat(strjoin, sep);
		i++;
	}
	return (strjoin);
}
/*
int	main(void)
{
	char	**strs = (char **)malloc(20);

	strs[0] = "Hello";
	strs[1] = "world";
	printf("strjoin: %s\n", ft_strjoin(2, strs, "."));
}
*/