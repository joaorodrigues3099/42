/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 07:29:56 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/24 07:30:00 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strmanp.h"

/**
 * Gets a sub-string from a parent string.
 *
 * @param s Parent string.
 * @param start Beginning of sub-string
 * @param len Max length of the sub-string
 * @return Returns the sub-string or NULL on fail.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	size_t			s_len;
	unsigned int	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len <= start)
		len = 0;
	else if (len > s_len - start)
		len = s_len - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < (unsigned int)len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
/*
int	main(void)
{
	printf("%s", ft_substr("Hello World!", 6, 6));
	return (0);
}
*/