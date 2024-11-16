/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_to_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <support@toujoustudios.net>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:46:46 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/30 15:46:46 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdlib.h"
#include <stdlib.h>

/**
 * Malloc space for a hexadecimal string.
 *
 * @return Returns a newly allocated 20 bytes string.
 */
char	*ft_create_hex_str(void)
{
	char	*hex_str;
	int		i;

	hex_str = (char *)malloc(20);
	if (!hex_str)
		return (NULL);
	i = 0;
	while (i < 20)
		hex_str[i++] = ' ';
	return (hex_str);
}

/**
 * Adds the '0x' or '0X' prefix to the hexadecimal string.
 *
 * @param hex_str Hexadecimal string.
 * @param hex_digits Hexadecimal alphabet.
 * @param flags Flags struct.
 * @param i Index of hex_str.
 */
void	ft_handle_cardinal(char *hex_str, const char *hex_digits,
							t_flags *flags, int *i)
{
	if (flags->cardinal)
	{
		if (hex_digits[15] == 'F')
			hex_str[(*i)--] = 'X';
		else
			hex_str[(*i)--] = 'x';
		hex_str[(*i)--] = '0';
	}
}

/**
 * Converts a value to hexadecimal.
 *
 * @param ptr Value to convert to hexadecimal.
 * @param hex_digits Hexadecimal alphabet to use.
 * @param flags Flags struct.
 * @return Returns a converted hexadecimal value.
 */
char	*ft_long_to_hex(unsigned long ptr, const char *hex_digits,
						t_flags *flags)
{
	char	*hex_str;
	char	*trimmed_hex_str;
	int		i;

	if (!ptr && flags->precision == -1)
		return ("0");
	hex_str = ft_create_hex_str();
	if (!hex_str)
		return (NULL);
	i = 19;
	hex_str[i--] = '\0';
	while (ptr)
	{
		hex_str[i--] = hex_digits[ptr % 16];
		ptr /= 16;
	}
	ft_handle_cardinal(hex_str, hex_digits, flags, &i);
	trimmed_hex_str = ft_strtrim(hex_str, " ");
	free(hex_str);
	return (trimmed_hex_str);
}
