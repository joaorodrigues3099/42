/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toupper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:34:04 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/22 13:34:12 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_charcheck.h"

/**
 * Converts a letter to uppercase
 * if there's an uppercase equivalent.
 *
 * @param c Letter to convert to uppercase.
 * @return Returns the converted value,
 * or c if conversion is not possible.
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
