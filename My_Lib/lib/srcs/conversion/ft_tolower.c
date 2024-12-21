/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:28:23 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/22 14:28:27 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.h"

/**
 * Converts a letter to lowercase
 * if there's a lowercase equivalent.
 *
 * @param c Letter to convert to lowercase.
 * @return Returns the converted value,
 * or c if conversion is not possible.
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
