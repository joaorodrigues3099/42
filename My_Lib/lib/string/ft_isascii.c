/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 22:16:32 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/17 22:16:40 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_string.h"

/**
 * Checks if a character is an ASCII table character.
 * Compares input to the decimal value on the ASCII table.
 *
 * @param c Character to check.
 * @return Returns 0 if the condition is false, 1 on true.
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
