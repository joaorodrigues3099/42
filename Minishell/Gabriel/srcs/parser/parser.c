/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <vigde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 12:17:28 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/03/03 12:17:31 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Create a new command structure
 * 
 * @return t_command* New command
 */
t_command	*create_command(void)
{
	t_command	*cmd;

	cmd = (t_command *)malloc(sizeof(t_command));
	if (!cmd)
		return (NULL);
	cmd->cmd = NULL;
	cmd->args = NULL;
	cmd->redirects = NULL;
	cmd->next = NULL;
	cmd->pipe_fd[0] = -1;
	cmd->pipe_fd[1] = -1;
	cmd->pid = -1;
	return (cmd);
}

/**
 * @brief Add a command to a command list
 * 
 * @param commands Command list
 * @param new_cmd New command to add
 */
void	add_command(t_command **commands, t_command *new_cmd)
{
	t_command	*tmp;

	if (!*commands)
	{
		*commands = new_cmd;
		return ;
	}
	tmp = *commands;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_cmd;
}

/**
 * @brief Process arguments for a command
 * 
 * @param cmd Command structure
 * @param token Token to process
 * @param shell The shell structure
 * @return int SUCCESS on success, ERROR on error
 */
static int	process_command_arg(t_command *cmd, t_token *token, t_shell *shell)
{
	int		i;
	int		argc;
	char	**new_args;
	char	*expanded;

	expanded = handle_quotes(token->value, shell);
	if (!expanded)
		return (ERROR);
	argc = 0;
	if (cmd->args)
		while (cmd->args[argc])
			argc++;
	new_args = (char **)malloc(sizeof(char *) * (argc + 2));
	if (!new_args)
		return (ERROR);
	i = 0;
	while (i < argc)
	{
		new_args[i] = cmd->args[i];
		i++;
	}
	new_args[i] = expanded;
	new_args[i + 1] = NULL;
	free(cmd->args);
	cmd->args = new_args;
	if (!cmd->cmd && cmd->args[0])
		cmd->cmd = ft_strdup(cmd->args[0]);
	return (SUCCESS);
}

/**
 * @brief Process redirection token
 * 
 * @param cmd Command structure
 * @param tokens Token list
 * @param current Current token
 * @param shell The shell structure
 * @return int SUCCESS on success, ERROR on error
 */
static int	process_redirection(t_command *cmd, t_token **tokens,
		t_token **current, t_shell *shell)
{
	t_token_type	type;
	char			*file;
	t_token			*next;

	type = (*current)->type;
	next = (*current)->next;
	if (!next || next->type != TOKEN_WORD)
	{
		syntax_error("newline");
		return (ERROR);
	}
	file = handle_quotes(next->value, shell);
	if (!file)
		return (ERROR);
	if (add_redirection(cmd, type, file) == ERROR)
	{
		free(file);
		return (ERROR);
	}
	*current = next;
	*tokens = (*tokens)->next;
	return (SUCCESS);
}

/**
 * @brief Parse tokens into commands
 * 
 * @param shell The shell structure
 * @return int SUCCESS on success, ERROR on error
 */
int	parse_tokens(t_shell *shell)
{
	t_token		*token;
	t_command	*current_cmd;

	token = shell->tokens;
	current_cmd = create_command();
	add_command(&shell->commands, current_cmd);
	while (token && token->type != TOKEN_EOF)
	{
		if (token->type == TOKEN_WORD)
		{
			if (process_command_arg(current_cmd, token, shell) == ERROR)
				return (ERROR);
		}
		else if (token->type == TOKEN_PIPE)
		{
			if (!current_cmd->cmd)
			{
				syntax_error("|");
				return (ERROR);
			}
			current_cmd = create_command();
			add_command(&shell->commands, current_cmd);
		}
		else if (token->type == TOKEN_REDIR_IN || token->type == TOKEN_REDIR_OUT
			|| token->type == TOKEN_REDIR_APPEND || token->type == TOKEN_HEREDOC)
		{
			if (process_redirection(current_cmd, &token, &token, shell) == ERROR)
				return (ERROR);
		}
		token = token->next;
	}
	return (handle_redirections(shell));
}

/**
 * @brief Main parsing function
 * 
 * @param shell The shell structure
 * @param input Input string
 * @return int SUCCESS on success, ERROR on error
 */
int	parse_input(t_shell *shell, char *input)
{
	if (!input || !*input)
		return (ERROR);
	if (check_quotes(input) == ERROR)
	{
		print_error(NULL, NULL, "unclosed quotes");
		return (ERROR);
	}
	if (lexer(shell, input) == ERROR)
		return (ERROR);
	if (parse_tokens(shell) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
