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

#include "lib_conversion.h"

/**
 * Advances the space ,tab and sign characters on the given string.
 * Also updated the sign flag to -1 if a minus is found in the correct place.
 *
 * @param str String to skip the prefix.
 * @param sign Sign to alter if the minus character is
 * present after the spaces and tabs.
 */
static void	ft_skip_prefix(const char **str, int *sign)
{
	while (**str == ' ' || (**str >= 9 && **str <= 13))
		(*str)++;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			*sign *= -1;
		(*str)++;
	}
}

/**
 *	Converts a given string to a decimal. Works like atoi, but
 *	converts numbers up to max llong or min llong.
 *
 * @param str String to atoll.
 * @param min Minimum allowed value.
 * @param max Maximum allowed value
 * @param valid Flag to check if number fits between min and max.
 * @return Returns the number given as string. If valid is not null,
 * changes it's value to 0 on invalid.
 */
long long	ft_atoll_valid(const char *str, const long long min,
		const long long max, int *valid)
{
	long long	atoll;
	int			sign;

	sign = 1;
	ft_skip_prefix(&str, &sign);
	atoll = 0;
	if (valid && !(*str >= '0' && *str <= '9'))
	{
		*valid = 0;
		return (0);
	}
	while (*str >= '0' && *str <= '9')
	{
		if (valid && ((sign == -1 && atoll > -(min + (*str - '0')) / 10)
				|| (sign == 1 && atoll > (max - (*str - '0')) / 10)))
		{
			*valid = 0;
			return (0);
		}
		atoll = atoll * 10 + *str - '0';
		str++;
	}
	return (atoll * sign);
}
