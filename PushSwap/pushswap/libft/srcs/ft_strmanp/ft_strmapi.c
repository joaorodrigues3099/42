/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:06:07 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/26 12:06:11 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strmanp.h"

/**
* Creates a copy of the givenString
 * where each character had Function f applied to.
 *
 * @param s String to map.
 * @param f Function to apply.
 * @return Returns a newly allocated copy of the given String
 * where each character had Function f applied to.
 */
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*mapi;
	unsigned int	i;

	if (!f || !s)
		return (NULL);
	mapi = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!mapi)
		return (NULL);
	i = 0;
	while (s[i])
	{
		mapi[i] = f(i, s[i]);
		i++;
	}
	mapi[i] = '\0';
	return (mapi);
}
