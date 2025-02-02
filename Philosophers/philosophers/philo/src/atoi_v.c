/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:30:13 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/23 15:30:28 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <limits.h>

/**
 * Converts a string to a long integer, considering sign and numerical limits.
 * Returns 0 if invalid input or if the result exceeds the limit of a long.
 *
 * @param str The string to convert.
 * @return The converted long integer or 0 if invalid.
 */
long	ft_atoi_v(const char *str)
{
	int			sign;
	long		res;

	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign *= -1;
	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		if (res > INT_MAX)
			break ;
		str++;
	}
	return (res * sign);
}
