/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:54:06 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/17 21:23:08 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_string.h"

/**
 * Checks if a character is alphabetic (A-Z) or (a-z).
 * Compares input to the decimal value on the ASCII table.
 *
 * @param c Character to check.
 * @return Returns 0 if the condition is false, 1 on true.
 */
int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
