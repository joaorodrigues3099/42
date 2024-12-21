/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:07:52 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/24 14:07:56 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strlib.h"

/**
 * Trims the given set of characters from the
 * beginning and end of a given string.
 *
 * @param s1 String to trim.
 * @param set Set of characters to trim.
 * @return Returns a newly allocated trimmed string,\n
 * Or NULL on failure.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	trimmed_len;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	trimmed_len = ft_strlen(s1);
	while (*s1 && ft_strchr(set, *s1))
	{
		s1++;
		trimmed_len--;
	}
	while (trimmed_len && ft_strchr(set, s1[trimmed_len - 1]))
		trimmed_len--;
	result = (char *)malloc(trimmed_len + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, trimmed_len + 1);
	return (result);
}
