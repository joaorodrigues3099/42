/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:35:34 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/23 19:35:38 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Allocates space for a new string anc copies the values from the given one.
 *
 * @param s String to duplicate.
 * @return Returns a pointer to the newly duplicated string,\n
 * Or NULL on memory allocqation fail.
 */
char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	s_length;

	s_length = ft_strlen(s);
	dup = ft_calloc(s_length + 1, sizeof(char));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, s_length + 1);
	return (dup);
}
