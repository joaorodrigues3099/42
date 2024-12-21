/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <support@toujoustudios.net>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:56:44 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/30 19:56:44 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fdlib.h"
#include "../../../includes/strlib.h"
#include <unistd.h>

/**
 * Prints a char according to the given flags
 * and counts the number of printed digits.
 *
 * @param c Character to print.
 * @param count Pointer to printed characters count.
 * @param flags Flag struct.
 */
void	ft_print_char(int c, int *count, t_flags *flags)
{
	int	extra_padding;

	extra_padding = flags->width - 1;
	if (extra_padding > 0 && !flags->minus)
	{
		while (extra_padding--)
			ft_putchar_count(' ', count);
	}
	ft_putchar_count(c, count);
	if (extra_padding > 0)
	{
		while (extra_padding--)
			ft_putchar_count(' ', count);
	}
}

/**
 * Prints a string according to the given flags
 * and counts the number of printed digits.
 * 
 * @param str String to print.
 * @param count Pointer to printed characters count.
 * @param flags Flag struct.
 */
void	ft_print_string(char *str, int *count, t_flags *flags)
{
	int	str_len;
	int	extra_padding;

	if (!str && (flags->precision >= 6 || flags->precision == -1))
		str = "(null)";
	else if (!str)
		str = "";
	str_len = (int)ft_strlen(str);
	if (flags->precision >= 0 && str_len >= flags->precision)
		str_len = flags->precision;
	if (flags->precision == -2)
		str_len = 0;
	extra_padding = flags->width - str_len;
	if (extra_padding > 0 && !flags->minus)
	{
		while (extra_padding--)
			ft_putchar_count(' ', count);
	}
	write(1, str, str_len);
	*count += str_len;
	if (extra_padding > 0)
	{
		while (extra_padding--)
			ft_putchar_count(' ', count);
	}
}
