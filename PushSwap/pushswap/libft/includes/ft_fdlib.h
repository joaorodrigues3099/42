/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdlib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <support@toujoustudios.net>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:53:52 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/08 22:53:52 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDLIB_H
#define FDLIB_H

/*
** ==========================================================
**                         Main Functions
** ==========================================================
*/

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_printf(const char *str, ...);

/*
** ==========================================================
**                         Printf Helpers
** ==========================================================
*/

//--------------------------Structures-----------------------
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

//------------------------Utilities---------------------------
void				ft_putchar_count(char c, int *count);
void				ft_putstr_count(const char *str, int *count);
t_flags				ft_flags(void);

//-------------------Unsigned Int Conversion------------------
char				*ft_unsigned_itoa(unsigned int n);

//--------------------Hexadecimal Conversion------------------
char				*ft_long_to_hex(unsigned long ptr, const char *hex_digits,
						t_flags *flags);

//--------------------Print Number's String-------------------
void				ft_print_n_string(char *n_string, int *count,
						t_flags *flags, int negative);

//--------------------String  Manipulation--------------------
char				*ft_strtrim(char const *s1, char const *set);

//---------------------------Printing-------------------------
void				ft_print_char(int c, int *count, t_flags *flags);
void				ft_print_string(char *str, int *count, t_flags *flags);
void				ft_print_pointer(void *ptr, int *count, t_flags *flags);
void				ft_print_number(int nbr, int *count, t_flags *flags);
void				ft_print_unsigned(unsigned int nbr, int *count, t_flags *flags);
void				ft_print_hexadecimal(unsigned int nbr, const char *base,
						int *count, t_flags *flags);

#endif //FDLIB_H
