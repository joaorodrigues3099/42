/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_conversion.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:19:50 by joao-alm          #+#    #+#             */
/*   Updated: 2024/12/26 19:35:12 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_CONVERSION_H
# define LIB_CONVERSION_H

char		*ft_itoa(int n);
int			ft_atoi(const char *nptr);
int			ft_toupper(int c);
int			ft_tolower(int c);
long long	ft_atoll_valid(const char *str, long long min, long long max,
				int *valid);

#endif // LIB_CONVERSION_H
