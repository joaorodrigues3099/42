/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <support@toujoustudios.net>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:06:37 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/28 17:06:48 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** ==========================================================
**                         Structures
** ==========================================================
*/

typedef struct s_flags
{
	int				minus;
	int				zero;
	int				cardinal;
	int				space;
	int				plus;
	int				width;
	int				precision;
	int				hex_caps;
}					t_flags;

/*
** ==========================================================
**                          Utilities
** ==========================================================
*/

void				ft_putchar_count(char c, int *count);
void				ft_putstr_count(const char *str, int *count);
int					ft_strlen(const char *str);
t_flags				ft_flags(void);

/*
** ==========================================================
**                      Input Validation
** ==========================================================
*/

char				*ft_valid_input(const char *str, t_flags *flags);

/*
** ==========================================================
**                   Unsigned Integer Conversion
** ==========================================================
*/

char				*ft_unsigned_itoa(unsigned int n);

/*
** ==========================================================
**                    String Manipulation
** ==========================================================
*/

char				*ft_strtrim(char const *s1, char const *set);

/*
** ==========================================================
**                 Print Number/String Helper
** ==========================================================
*/

void				ft_print_n_string(char *n_string, int *count,
						t_flags *flags, int negative);

/*
** ==========================================================
**                     Hexadecimal Conversion
** ==========================================================
*/

char				*ft_long_to_hex(unsigned long ptr, const char *hex_digits,
						t_flags *flags);

/*
** ==========================================================
**                         Printing
** ==========================================================
*/

void				ft_print_char(int c, int *count, t_flags *flags);
void				ft_print_string(char *str, int *count, t_flags *flags);
void				ft_print_pointer(void *ptr, int *count, t_flags *flags);
void				ft_print_number(int nbr, int *count, t_flags *flags);
void				ft_print_unsigned(unsigned int nbr, int *count, t_flags *flags);
void				ft_print_hexadecimal(unsigned int nbr, const char *base,
						int *count, t_flags *flags);

/*
** ==========================================================
**                         Printing
** ==========================================================
*/

int				ft_printf(const char *str, ...);

#endif
