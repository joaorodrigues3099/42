/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:47:52 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/18 15:47:52 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/charlib.h"

/**
 * Checks if a character is a printable value.
 * Compares input to the decimal value on the ASCII table.
 *
 * @param c Character to check.
 * @return Returns 0 if the condition is false, 1 on true.
 */
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
