/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdec_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <support@toujoustudios.net>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:35:22 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/29 14:35:22 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdlib.h"
#include "strmanp.h"

/**
 *
 * @param extra_padding Number of padding to print.
 * @param zeros 1 for zeros, 0 for spaces.
 * @param count Pointer to printed characters count.
 */
void	ft_fill_width(int extra_padding, int zeros, int *count)
{
	char	padding;

	padding = ' ';
	if (zeros)
		padding = '0';
	while (extra_padding--)
		ft_putchar_count(padding, count);
}

/**
 * Prints a sign or space if needed.
 *
 * @param negative 1 if negative, 0 if not.
 * @param count Pointer to printed characters count.
 * @param flags Flag struct.
 */
void	ft_put_signs(int negative, int *count, const t_flags *flags)
{
	if (negative)
		ft_putchar_count('-', count);
	if (flags->plus && !negative)
		ft_putchar_count('+', count);
	if (flags->space && !negative)
		ft_putchar_count(' ', count);
}

/**
 * Prints a string containing a number according to the given flags
 * and counts the number of printed digits.
 *
 * @param n_string String containing the number to print.
 * @param count Pointer to printed characters count.
 * @param flags Flag struct.
 * @param negative 1 if negative, 0 if not.
 */
void	ft_print_n_string(char *n_string, int *count, t_flags *flags,
						int negative)
{
	int	str_len;
	int	precision;
	int	extra_padding;

	if (flags->precision != -1)
		flags->zero = 0;
	str_len = (int)ft_strlen(n_string);
	precision = flags->precision - str_len;
	if (precision < 0)
		precision = 0;
	extra_padding = flags->width - str_len - precision - negative - flags->plus
		- flags->space;
	if (flags->zero)
		ft_put_signs(negative, count, flags);
	if (extra_padding > 0 && !flags->minus)
		ft_fill_width(extra_padding, flags->zero, count);
	if (!flags->zero)
		ft_put_signs(negative, count, flags);
	if (precision > 0)
		ft_fill_width(precision, 1, count);
	flags->width = 0;
	flags->precision = -1;
	ft_print_string(n_string, count, flags);
	if (extra_padding > 0 && flags->minus)
		ft_fill_width(extra_padding, 0, count);
}
