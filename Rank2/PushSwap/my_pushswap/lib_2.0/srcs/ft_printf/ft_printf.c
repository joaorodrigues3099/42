/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <support@toujoustudios.net>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:57:46 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/05 21:48:41 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

/**
 * Prints the given arg in the stdout.
 *
 * @param args va_list containing all the Values for '%'.
 * @param str Main string containing the '%'.
 * @param count Pointer to printed digits counter.
 * @param flags Flags struct.
 */
static void	ft_handle_args(va_list args, const char *str, int *count,
						t_flags *flags)
{
	if (*str == 'c')
		ft_print_char(va_arg(args, int), count, flags);
	else if (*str == 's')
		ft_print_string(va_arg(args, char *), count, flags);
	else if (*str == 'p')
		ft_print_pointer(va_arg(args, void *), count, flags);
	else if (*str == 'd' || *str == 'i')
		ft_print_number(va_arg(args, int), count, flags);
	else if (*str == 'u')
		ft_print_unsigned(va_arg(args, unsigned int), count, flags);
	else if (*str == 'x')
		ft_print_hexadecimal(va_arg(args, unsigned int), "0123456789abcdef",
			count, flags);
	else if (*str == 'X')
		ft_print_hexadecimal(va_arg(args, unsigned int), "0123456789ABCDEF",
			count, flags);
	else if (*str == '%')
		ft_putchar_count('%', count);
}

/**
 * Sets the '-0# +' flags
 *
 * @param flags Flags struct.
 * @param str Main string containing the '%'.
 */
static void	ft_handle_flags(t_flags *flags, const char **str)
{
	while (**str == '-' || **str == '0' || **str == '#' || **str == ' '
		|| **str == '+')
	{
		if (**str == '-')
			flags->minus = 1;
		else if (**str == '0' && !flags->minus)
			flags->zero = 1;
		else if (**str == '#')
			flags->cardinal = 1;
		else if (**str == '+')
			flags->plus = 1;
		else if (**str == ' ' && !flags->plus)
			flags->space = 1;
		(*str)++;
	}
}

/**
 * Sets the width and precision flags.
 * 
 * @param flags Flags struct.
 * @param str Main string containing the '%'.
 */
static void	ft_handle_width_precision(t_flags *flags, const char **str)
{
	while (**str >= '0' && **str <= '9')
	{
		flags->width *= 10;
		flags->width += **str - '0';
		(*str)++;
	}
	if (**str == '.')
	{
		(*str)++;
		flags->precision = -2;
		if (**str >= '0' && **str <= '9')
			flags->precision = 0;
		while (**str >= '0' && **str <= '9')
		{
			flags->precision *= 10;
			flags->precision += **str - '0';
			(*str)++;
		}
	}
}

/**
 * Handles every '%' with flags included.
 *
 * @param args va_list containing all the Values for '%'.
 * @param str Main string containing the '%'.
 * @param count Pointer to printed digits counter.
 * @param flags Flags struct.
 */
static void	ft_handle_input(va_list args, const char **str, int *count,
						t_flags *flags)
{
	(*str)++;
	*flags = ft_flags();
	ft_handle_flags(flags, str);
	ft_handle_width_precision(flags, str);
	ft_handle_args(args, *str, count, flags);
}

/**
 * Replicates the printf function from cLib
 * 
 * @param str Main string containing the '%'.
 * @param ... Values for the '%'s.
 * @return Returns the count of the printed digits.
 */
int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	t_flags	flags;

	va_start(args, str);
	count = 0;
	flags = ft_flags();
	while (*str)
	{
		if (*str == '%' && *(str + 1))
			ft_handle_input(args, &str, &count, &flags);
		else
			ft_putchar_count(*str, &count);
		str++;
	}
	va_end(args);
	return (count);
}
