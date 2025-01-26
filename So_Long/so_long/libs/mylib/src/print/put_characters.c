/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_characters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <support@toujoustudios.net>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 22:08:03 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/30 22:08:03 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_print.h"
#include <unistd.h>

/**
 * Prints a char and increments count by 1.
 *
 * @param c Character to print.
 * @param count Pointer to printed characters count.
 */
void	ft_putchar_count(int c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

/**
 * Prints a String and increments count by the number of characters printed.
 *
 * @param str String to print.
 * @param count Pointer to printed characters count.
 */
void	ft_putstr_count(char *str, int *count)
{
	if (!str)
	{
		ft_putstr_count("(null)", count);
		return ;
	}
	while (*str)
		ft_putchar_count(*str++, count);
}
