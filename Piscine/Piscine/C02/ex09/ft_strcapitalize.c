/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:29:33 by joao-alm          #+#    #+#             */
/*   Updated: 2024/07/19 07:01:20 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	check_alpha(char *str, int pos)
{
	if (str[pos] >= 'a' && str[pos] <= 'z')
		return (1);
	else if (str[pos] >= 'A' && str[pos] <= 'Z')
		return (2);
	else if (str[pos] >= '0' && str[pos] <= '9')
		return (3);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i -1;
		if (i == 0)
		{
			if (check_alpha(str, i) == 1)
				str[i] = str[i] - 32;
		}
		else if (check_alpha(str, i) == 2 && check_alpha(str, j) != 0)
			str[i] = str[i] + 32;
		else if (check_alpha(str, i) == 1)
		{
			if (check_alpha(str, j) == 0)
			{
				str[i] = str[i] - 32;
			}
		}
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	char	str[] = "salut, comment tu vas ? 42mots quarante-deux";

	printf("Old string was: %s \n", str);
	printf("New string is: %s", ft_strcapitalize(str));
}
*/