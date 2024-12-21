/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:47:59 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/24 21:48:02 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Counts the number of 'words' in the given String.
 *
 * @param s String to count from.
 * @param c Separator.
 * @return Returns the number of 'words' that the given String contains.
 */
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

/**
 * Creates and copies the given amount of characters of the given String,
 * to the newly allocated 'word'.
 *
 * @param start String to start copying from.
 * @param len Number of characters to copy.
 * @return Returns a null-terminated 'word'.
 */
static char	*ft_alloc_word(const char *start, size_t len)
{
	char	*word;
	size_t	i;

	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

/**
 * Frees all previously allocated functions from an array
 * and the array itself.
 *
 * @param split Array of strings to free.
 * @param i Current index on the array
 */
static void	ft_free_split(char **split, int i)
{
	while (i >= 0)
	{
		free(split[i]);
		i--;
	}
	free(split);
}

/**
 * Fills the given Array of Strings with the 'words'
 * (delimited by the separator or start/end).
 *
 * @param split Array of Strings to fill.
 * @param s String to split.
 * @param c Separator.
 * @return Returns a null-terminated array of Strings with the 'words'
 */
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

/**
 * Splits a given String into 'words'.
 *
 * @param s String to split.
 * @param c Separator.
 * @return Returns a null-terminated array of Strings,
 * containing the 'words' previously delimited
 * by the given separator or start/end.
 */
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
/*
#include <stdio.h>

int	main(void)
{
	char	**split;
	int	n_strings;

	n_strings = 2;
	split = ft_split(" hello world ", ' ');
	for (int i = 0; i < n_strings; i++)
		printf("%s\n", split[i]);
	ft_free_split(split, 2);
	return (0);
}
*/