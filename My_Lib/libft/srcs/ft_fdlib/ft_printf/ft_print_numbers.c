/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <support@toujoustudios.net>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:19:53 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/30 16:19:53 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdlib.h"
#include <stdlib.h>

/**
 * Prints a given int according to the given flags.
 *
 * @param nbr Number to print.
 * @param count Pointer to printed characters count.
 * @param flags Flag struct.
 */
void	ft_print_number(int nbr, int *count, t_flags *flags)
{
	char	*n_string;

	if (nbr < 0)
		n_string = ft_unsigned_itoa((unsigned int)-nbr);
	else
		n_string = ft_unsigned_itoa((unsigned int)nbr);
	if (!n_string)
		return ;
	if (nbr < 0)
	{
		flags->plus = 0;
		flags->space = 0;
	}
	if ((!flags->precision || flags->precision == -2) && !nbr)
	{
		flags->space = 0;
		flags->zero = 0;
		ft_print_n_string("", count, flags, nbr < 0);
	}
	else
		ft_print_n_string(n_string, count, flags, nbr < 0);
	free(n_string);
}

/**
 * Prints a given unsigned int according to the given flags.
 *
 * @param nbr Number to print.
 * @param count Pointer to printed characters count.
 * @param flags Flag struct.
 */
void	ft_print_unsigned(unsigned int nbr, int *count, t_flags *flags)
{
	char	*n_string;

	n_string = ft_unsigned_itoa(nbr);
	if (!n_string)
		return ;
	if ((!flags->precision || flags->precision == -2) && !nbr)
		ft_print_n_string("", count, flags, 0);
	else
		ft_print_n_string(n_string, count, flags, 0);
	free(n_string);
}

/**
 * Prints a given pointer address according to the given flags.
 *
 * @param ptr Pointer to print.
 * @param count Pointer to printed characters count.
 * @param flags Flag struct.
 */
void	ft_print_pointer(void *ptr, int *count, t_flags *flags)
{
	char	*hex_str;

	if (!ptr)
	{
		ft_print_string("(nil)", count, flags);
		return ;
	}
	flags->cardinal = 1;
	hex_str = ft_long_to_hex((unsigned long)ptr, "0123456789abcdef", flags);
	if (!hex_str)
		return ;
	ft_print_string(hex_str, count, flags);
	free(hex_str);
}

/**
 * Prints a nbr in the given hexadecimal base.
 *
 * @param nbr Number to print in hexadecimal.
 * @param base Hexadecimal base to print on.
 * @param count Pointer to printed characters count.
 * @param flags Flag struct.
 */
void	ft_print_hexadecimal(unsigned int nbr, const char *base, int *count,
							t_flags *flags)
{
	char	*hex;

	hex = ft_long_to_hex(nbr, base, flags);
	if (!hex)
		return ;
	if ((!flags->precision || flags->precision == -2) && !nbr)
		ft_print_n_string("", count, flags, 0);
	else
		ft_print_n_string(hex, count, flags, 0);
	if (!(hex[0] == '0' && hex[1] == '\0'))
		free(hex);
}
