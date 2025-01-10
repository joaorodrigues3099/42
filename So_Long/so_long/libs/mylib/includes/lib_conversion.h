/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:08:57 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/29 20:09:04 by joao-alm         ###   ########.fr       */
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

#endif //LIB_CONVERSION_H
