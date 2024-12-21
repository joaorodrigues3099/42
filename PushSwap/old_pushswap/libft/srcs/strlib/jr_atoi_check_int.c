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

#include "../../includes/charlib.h"
#include "../../includes/strlib.h"
#include <limits.h>

/**
 * Gets an int number from a string containing the number.
 *
 * @param nptr String containing the number.
 * @return Returns the number, 0 if invalid.
 */
long	ft_atoi_check_int(const char *nptr)
{
	long	result;
	long	checker;
	int		sign;

	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	sign = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	result = 0;
	if (!ft_isdigit(*nptr))
		return (INT_OVERFLOW);
	while (ft_isdigit(*nptr))
	{
		checker = result * 10 + (*nptr - '0');
		if (checker > INT_MAX)
			return (INT_OVERFLOW);
        result = checker;
		nptr++;
	}
	return (result * sign);
}
