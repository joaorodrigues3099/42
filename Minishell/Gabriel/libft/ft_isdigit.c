/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:02:31 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/10/24 11:25:27 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
int	main()
{
	printf("Testando '0': %d\n", ft_isdigit('0'));
	printf("Testando '9': %d\n", ft_isdigit('9'));
	printf("Testando 'a': %d\n", ft_isdigit('a'));
	printf("Testando '+': %d\n", ft_isdigit('+'));
	return (0);
}*/
