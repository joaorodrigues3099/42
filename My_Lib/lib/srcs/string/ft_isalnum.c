/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:30:08 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/17 21:34:02 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

/**
 * Checks if a character is alphabetic or numeric (A-Z) or (a-z) or (0-9).
 * Compares input to the decimal value on the ASCII table.
 *
 * @param c Character to check.
 * @return Returns 0 if the condition is false, 1 on true.
 */
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
