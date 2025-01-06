/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao─alm <joao─alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:34:27 by joao─alm          #+#    #+#             */
/*   Updated: 2024/11/27 17:34:27 by joao─alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//────────────────────────────────────Main Function────────────────────────────────
int	ft_printf(const char *str, ...);

//────────────────────────────────────Structure────────────────────────────────
typedef struct s_flags
{
	int	minus;
	int	zero;
	int	cardinal;
	int	space;
	int	plus;
	int	width;
	int	precision;
	int	hex_caps;
}		t_flags;

//────────────────────────────────────Utilities─────────────────────────────────
void	ft_putchar_count(char c, int *count);
void	ft_putstr_count(const char *str, int *count);
t_flags	ft_flags(void);

//────────────────────────────────────Conversion─────────────────────────────────
char	*ft_unsigned_itoa(unsigned int n);
char	*ft_long_to_hex(unsigned long ptr, const char *hex_digits,
			t_flags *flags);

//─────────────────────────────────────Printing──────────────────────────────────
void	ft_print_char(int c, int *count, t_flags *flags);
void	ft_print_string(char *str, int *count, t_flags *flags);
void	ft_print_pointer(void *ptr, int *count, t_flags *flags);
void	ft_print_number(int nbr, int *count, t_flags *flags);
void	ft_print_n_string(char *n_string, int *count, t_flags *flags,
			int negative);
void	ft_print_unsigned(unsigned int nbr, int *count, t_flags *flags);
void	ft_print_hexadecimal(unsigned int nbr, const char *base, int *count,
			t_flags *flags);

#endif // FT_PRINTF_H
