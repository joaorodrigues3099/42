/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 18:00:18 by joao-alm          #+#    #+#             */
/*   Updated: 2024/07/14 11:08:40 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
*/
int	ft_strlen(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos] != 0)
	{
		pos++;
	}
	return (pos);
}
/*
int	main(void)
{
	int		count;
	char	*str;

	count = 0;
	str = "Hello World!";
	count = ft_strlen(str);
	ft_putchar(48 + count / 10);
	ft_putchar(48 + count % 10);
	return (0);
}
*/
