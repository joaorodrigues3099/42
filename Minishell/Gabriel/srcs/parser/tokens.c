/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <vigde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 12:17:28 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/03/03 12:17:31 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h" 

/**
 * @brief Check if character is a space
 * 
 * @param c Character to check
 * @return int 1 if space, 0 otherwise
 */
int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

/**
 * @brief Check if character is a delimiter
 * 
 * @param c Character to check
 * @return int 1 if delimiter, 0 otherwise
 */
int	is_delimiter(char c)
{
	return (is_space(c) || c == '|' || c == '<' || c == '>' || c == '\0');
}

/**
 * @brief Get token type from string
 * 
 * @param str String to check
 * @return t_token_type Token type
 */
int	get_token_type(char *str)
{
	if (!str || !*str)
		return (TOKEN_EOF);
	if (*str == '|')
		return (TOKEN_PIPE);
	if (*str == '<')
	{
		if (*(str + 1) == '<')
			return (TOKEN_HEREDOC);
		return (TOKEN_REDIR_IN);
	}
	if (*str == '>')
	{
		if (*(str + 1) == '>')
			return (TOKEN_REDIR_APPEND);
		return (TOKEN_REDIR_OUT);
	}
	return (TOKEN_WORD);
}

/**
 * @brief Get token value from string
 * 
 * @param str String to check
 * @param i Position in string
 * @return char* Token value
 */
char	*get_token_value(char *str, int *i)
{
	int		start;
	int		len;
	char	quote;

	start = *i;
	if (str[*i] == '|')
		(*i)++;
	else if (str[*i] == '<' || str[*i] == '>')
	{
		if (str[*i + 1] == str[*i])
			(*i) += 2;
		else
			(*i)++;
	}
	else
	{
		while (str[*i] && !is_delimiter(str[*i]))
		{
			if (str[*i] == '\'' || str[*i] == '\"')
			{
				quote = str[(*i)++];
				while (str[*i] && str[*i] != quote)
					(*i)++;
				if (str[*i])
					(*i)++;
			}
			else
				(*i)++;
		}
	}
	len = *i - start;
	return (ft_substr(str, start, len));
}
