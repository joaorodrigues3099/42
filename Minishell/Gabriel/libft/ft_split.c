/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:46:22 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/10/24 15:50:33 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_count_words(const char *s, char c)
{
	unsigned int	count;
	int				in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			count++;
			in_word = 1;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*ft_alloc_word(const char *start, size_t len)
{
	char	*word;
	size_t	i;

	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = -1;
	while (++i < len)
		word[i] = start[i];
	word[i] = '\0';
	return (word);
}

static void	ft_free_split(char **split, int i)
{
	while (i)
	{
		free(split[i]);
		i--;
	}
	free(split);
}

static char	**ft_fill_split(char **split, const char *s, char c)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c)
			{
				len++;
				s++;
			}
			split[i++] = ft_alloc_word(s - len, len);
			if (!split[i - 1])
				return (ft_free_split(split, i - 1), NULL);
		}
		else
			s++;
	}
	split[i] = NULL;
	return (split);
}

char	**ft_split(const char *s, char c)
{
	unsigned int	n_words;
	char			**split;

	if (!s)
		return (NULL);
	n_words = ft_count_words(s, c);
	split = (char **)malloc((n_words + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	return (ft_fill_split(split, s, c));
}
