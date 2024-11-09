/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <support@toujoustudios.net>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:51:02 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/28 17:51:02 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdlib.h"
#include "ft_strmanp.h"
#include <unistd.h>

/**
 * Prints a char and increments count by 1.
 *
 * @param c Character to print.
 * @param count Pointer to printed characters count.
 */
void	ft_putchar_count(char c, int *count)
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
void	ft_putstr_count(const char *str, int *count)
{
	int	str_len;

	str_len = (int)ft_strlen(str);
	write(1, str, str_len);
	*count += str_len;
}

/**
 * Flags struct.
 *
 * @return Flags struct.
 */
t_flags	ft_flags(void)
{
	t_flags	flags;

	flags.minus = 0;
	flags.zero = 0;
	flags.cardinal = 0;
	flags.space = 0;
	flags.plus = 0;
	flags.width = 0;
	flags.precision = -1;
	return (flags);
}
