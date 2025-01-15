/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:42:19 by joao-alm          #+#    #+#             */
/*   Updated: 2024/07/24 17:17:51 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	return (ft_fibonacci(index -1) + ft_fibonacci(index - 2));
}
/*
int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("return: %d\n", ft_fibonacci(atoi(argv[1])));
	return (0);
}
*/