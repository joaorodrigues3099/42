/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:47:34 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/23 13:15:48 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_string.h"

/**
 * Searches for a string (needle/little) inside another string (haystack/big).
 *
 * @param big String where little can be located (haystack).
 * @param little String to search inside big (needle).
 * @param len Number of bytes to search in big.
 * @return Returns a pointer for the first occurrence of little
 * inside big.\n
 * If little len is 0, returns big.\n
 * If little is not found, returns NULL.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!big && !len)
		return (NULL);
	if (!*little)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (little[j] && i + j < len && big[i + j] == little[j])
				j++;
			if (!little[j])
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
