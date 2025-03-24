/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <vigde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 12:17:28 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/03/03 12:17:31 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h" 

/**
 * @brief Check if quotes are balanced in input
 * 
 * @param input Input string
 * @return int SUCCESS if balanced, ERROR otherwise
 */
int	check_quotes(char *input)
{
	int		i;
	char	quote;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\'' || input[i] == '\"')
		{
			quote = input[i++];
			while (input[i] && input[i] != quote)
				i++;
			if (!input[i])
				return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

/**
 * @brief Check if character at index is quoted
 * 
 * @param str Input string
 * @param index Index to check
 * @return int 1 if quoted, 0 otherwise
 */
int	is_quoted(char *str, int index)
{
	int		i;
	char	quote;
	int		in_quote;

	if (!str || index < 0 || index >= (int)ft_strlen(str))
		return (0);
	i = 0;
	in_quote = 0;
	while (i < index)
	{
		if ((str[i] == '\'' || str[i] == '\"') && !in_quote)
		{
			in_quote = 1;
			quote = str[i];
		}
		else if (in_quote && str[i] == quote)
			in_quote = 0;
		i++;
	}
	return (in_quote);
}

/**
 * @brief Get length of expanded string
 * 
 * @param str String to expand
 * @param shell The shell structure
 * @return int Length of expanded string
 */
static int	get_expanded_len(char *str, t_shell *shell)
{
	int		i;
	int		len;
	char	*var;
	char	*value;
	int		in_single_quote;

	i = 0;
	len = 0;
	in_single_quote = 0;
	while (str[i])
	{
		if (str[i] == '\'' && !is_quoted(str, i))
			in_single_quote = !in_single_quote;
		else if (str[i] == '$' && !in_single_quote && str[i + 1]
			&& (ft_isalnum(str[i + 1]) || str[i + 1] == '_' || str[i + 1] == '?'))
		{
			i++;
			var = ft_strdup("");
			while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
			{
				var = ft_strjoin(var, ft_substr(str, i, 1));
				i++;
			}
			if (ft_strncmp(var, "", ft_strlen(var) + 1) == 0 && str[i] == '?')

			{
				free(var);
				var = ft_strdup("?");
				i++;
			}
			if (ft_strncmp(var, "?", 2) == 0)
				value = ft_itoa(shell->exit_status);
			else
				value = get_env_value(var, shell->env);
			if (value)
				len += ft_strlen(value);
			free(var);
			if (str[i] == '\0')
				break ;
		}
		else
			len++;
		i++;
	}
	return (len);
}

/**
 * @brief Expand variables in string
 * 
 * @param str String to expand
 * @param shell The shell structure
 * @return char* Expanded string
 */
static char	*expand_variables(char *str, t_shell *shell)
{
	int		i;
	int		j;
	char	*result;
	char	*var;
	char	*value;
	int		in_single_quote;

	i = 0;
	j = 0;
	in_single_quote = 0;
	result = (char *)malloc(sizeof(char) * (get_expanded_len(str, shell) + 1));
	if (!result)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\'' && !is_quoted(str, i))
			in_single_quote = !in_single_quote;
		else if (str[i] == '$' && !in_single_quote && str[i + 1]
			&& (ft_isalnum(str[i + 1]) || str[i + 1] == '_' || str[i + 1] == '?'))
		{
			i++;
			var = ft_strdup("");
			while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
			{
				var = ft_strjoin(var, ft_substr(str, i, 1));
				i++;
			}
			if (ft_strncmp(var, "", ft_strlen(var) + 1) == 0 && str[i] == '?')

			{
				free(var);
				var = ft_strdup("?");
				i++;
			}
			if (ft_strncmp(var, "?", 2) == 0)
				value = ft_itoa(shell->exit_status);
			else
				value = get_env_value(var, shell->env);
			if (value)
			{
				 ft_strlcpy(&result[j], value, ft_strlen(value) + 1);
				j += ft_strlen(value);
			}
			free(var);
			if (str[i] == '\0')
				break ;
		}
		else
			result[j++] = str[i++];
	}
	result[j] = '\0';
	return (result);
}

/**
 * @brief Remove quotes from string
 * 
 * @param str String to process
 * @return char* String without quotes
 */
char	*remove_quotes(char *str)
{
	int		i;
	int		j;
	char	*result;
	char	quote;

	i = 0;
	j = 0;
	result = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!result)
		return (NULL);
	while (str[i])
	{
		if ((str[i] == '\'' || str[i] == '\"') && !is_quoted(str, i))
		{
			quote = str[i++];
			while (str[i] && str[i] != quote)
				result[j++] = str[i++];
			if (str[i])
				i++;
		}
		else
			result[j++] = str[i++];
	}
	result[j] = '\0';
	return (result);
}

/**
 * @brief Handle quotes and expand variables
 * 
 * @param str String to process
 * @param shell The shell structure
 * @return char* Processed string
 */
char	*handle_quotes(char *str, t_shell *shell)
{
	char	*expanded;
	char	*unquoted;

	expanded = expand_variables(str, shell);
	if (!expanded)
		return (NULL);
	unquoted = remove_quotes(expanded);
	free(expanded);
	return (unquoted);
}
