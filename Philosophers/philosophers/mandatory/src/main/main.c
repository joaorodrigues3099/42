/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopedro </var/spool/mail/joaopedrorodri> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:29:18 by joaopedro         #+#    #+#             */
/*   Updated: 2025/01/26 13:33:37 by joaopedro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


int ft_get_int(const int value)
{
	int res;

	res = 0;
	if (value < 0)
		while (res > value)
			res--;
	else
		while (res < value)
			res++;
	return (res);
}

int	main(void)
{
	printf("%d\n", ft_get_int(-2000));
	return (0);
}
