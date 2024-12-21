/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:36:09 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/17 20:33:35 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/charlib.h"

/**
 * Checks if a character is numeric (0-9).
 * Compares input to the decimal value on the ASCII table.
 *
 * @param c Character to check.
 * @return Returns 0 if the condition is false, 1 on true.
 */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
