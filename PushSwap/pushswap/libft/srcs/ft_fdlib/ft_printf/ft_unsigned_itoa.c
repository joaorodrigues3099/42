/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:29:31 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/25 21:30:56 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdlib.h"

/**
 * Counts the number of digits from a given Int.
 *
 * @param n Number to count digits of.
 * @return Returns the number of digits of an Int number.
 * If the number is negative, returns one extra value in count,
 * to account for the negative sign.
 */
static unsigned int	ft_digit_count(unsigned int n)
{
	unsigned int	count;

	count = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

/**
 * Converts an Unsigned Number from Int to a null-terminated String.
 *
 * @param n Unsigned Number to get String from.
 * @return Return the Number given as a String.
 * Or NULL on failed memory allocation.
 */
char	*ft_unsigned_itoa(unsigned int n)
{
	char			*itoa;
	unsigned int	n_digits;

	n_digits = ft_digit_count(n);
	itoa = (char *)malloc((n_digits + 1) * sizeof(char));
	if (!itoa)
		return (NULL);
	itoa[n_digits--] = '\0';
	if (n == 0)
		itoa[0] = '0';
	while (n)
	{
		itoa[n_digits--] = '0' + (n % 10);
		n /= 10;
	}
	return (itoa);
}
