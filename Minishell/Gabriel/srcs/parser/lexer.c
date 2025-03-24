/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <vigde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 12:17:28 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/03/03 12:17:31 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Create a new token
 * 
 * @param type Token type
 * @param value Token value
 * @return t_token* New token
 */
t_token	*create_token(t_token_type type, char *value)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->type = type;
	token->value = value;
	token->next = NULL;
	return (token);
}

/**
 * @brief Add a token to a token list
 * 
 * @param tokens Token list
 * @param new_token New token to add
 */
void	add_token(t_token **tokens, t_token *new_token)
{
	t_token	*tmp;

	if (!*tokens)
	{
		*tokens = new_token;
		return ;
	}
	tmp = *tokens;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_token;
}

/**
 * @brief Process a token from input
 * 
 * @param shell The shell structure
 * @param input Input string
 * @param i Position in input
 * @return int SUCCESS on success, ERROR on error
 */
static int	process_token(t_shell *shell, char *input, int *i)
{
	t_token_type	type;
	char			*value;

	while (input[*i] && is_space(input[*i]))
		(*i)++;
	if (!input[*i])
		return (SUCCESS);
	type = get_token_type(input + *i);
	value = get_token_value(input, i);
	if (!value)
		return (ERROR);
	add_token(&shell->tokens, create_token(type, value));
	return (SUCCESS);
}

/**
 * @brief Tokenize input string
 * 
 * @param shell The shell structure
 * @param input Input string
 * @return int SUCCESS on success, ERROR on error
 */
int	lexer(t_shell *shell, char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (process_token(shell, input, &i) == ERROR)
			return (ERROR);
	}
	add_token(&shell->tokens, create_token(TOKEN_EOF, ft_strdup("")));
	return (SUCCESS);
}
