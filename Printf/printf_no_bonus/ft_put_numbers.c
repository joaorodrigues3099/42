/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <support@toujoustudios.net>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 22:13:31 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/30 22:13:31 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * Prints a nbr in the given hexadecimal base.
 *
 * @param ptr Number to print in hexadecimal.
 * @param hex_digits Hexadecimal alphabet to print in.
 * @param count Pointer to printed characters count.
 */
void	ft_put_hex_count(unsigned long ptr, const char *hex_digits, int *count)
{
	if (ptr >= 16)
	{
		ft_put_hex_count(ptr / 16, hex_digits, count);
		ft_putchar_count(hex_digits[ptr % 16], count);
	}
	else
		ft_putchar_count(hex_digits[ptr % 16], count);
}

/**
 * Prints a ptr in the given hexadecimal base.
 *
 * @param ptr Number to print in hexadecimal.
 * @param count Pointer to printed characters count.
 */
void	ft_putptr_count(void *ptr, int *count)
{
	if (!ptr)
	{
		ft_putstr_count("(nil)", count);
		return ;
	}
	ft_putstr_count("0x", count);
	ft_put_hex_count((unsigned long)ptr, "0123456789abcdef", count);
}

/**
 * Prints an unsigned nbr.
 *
 * @param nbr Unsigned number to print.
 * @param count Pointer to printed characters count.
 */
void	ft_putnbr_unsigned_count(unsigned int nbr, int *count)
{
	if (nbr >= 10)
	{
		ft_putnbr_count(nbr / 10, count);
		ft_putchar_count('0' + nbr % 10, count);
	}
	else
		ft_putchar_count('0' + nbr % 10, count);
}

/**
 * Prints a number.
 *
 * @param nbr Number to print.
 * @param count Pointer to printed characters count.
 */
void	ft_putnbr_count(int nbr, int *count)
{
	if (nbr < 0)
	{
		ft_putchar_count('-', count);
		nbr = -nbr;
	}
	ft_putnbr_unsigned_count(nbr, count);
}
