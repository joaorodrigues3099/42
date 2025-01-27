/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notlibft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:35:31 by joao-alm          #+#    #+#             */
/*   Updated: 2025/01/27 11:35:31 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NOTLIBFT_H
#define NOTLIBFT_H

#include <stdlib.h>

size_t		ft_strlen(const char *s);
long long	ft_atoll_valid(const char *str, long long min,
	long long max, int *valid);

#endif //NOTLIBFT_H
