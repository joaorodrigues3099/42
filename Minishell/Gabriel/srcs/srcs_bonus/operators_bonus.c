/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <vigde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 12:17:28 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/03/03 12:17:31 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

/**
 * @brief Create an AST node
 * 
 * @param cmd Command structure
 * @param op Operator type
 * @return t_ast_node* New AST node
 */
t_ast_node	*create_ast_node(t_command *cmd, t_operator op)
{
	t_ast_node	*node;

	node = (t_ast_node *)malloc(sizeof(t_ast_node));
	if (!node)
		return (NULL);
	node->cmd = cmd;
	node->op = op;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

/**
 * @brief Free an AST
 * 
 * @param root Root node of the AST
 */
void	free_ast(t_ast_node *root)
{
	if (!root)
		return ;
	free_ast(root->left);
	free_ast(root->right);
	free(root);
}

/**
 * @brief Find logical operators (&&, ||) in input
 * 
 * @param input Input string
 * @param index Position in input
 * @param op Operator to find
 * @return int Position of operator or -1 if not found
 */
static int	find_operator(char *input, int index, char *op)
{
	int	i;
	int	in_quote;
	int	len;

	i = index;
	in_quote = 0;
	len = ft_strlen(op);
	while (input[i])
	{
		if ((input[i] == '\'' || input[i] == '\"') && !is_quoted(input, i))
			in_quote = !in_quote;
		else if (!in_quote && ft_strncmp(&input[i], op, len) == 0)
			return (i);
		i++;
	}
	return (-1);
}

/**
 * @brief Build AST from input
 * 
 * @param shell_bonus Shell bonus structure
 * @param input Input string
 * @param start Start position in input
 * @param end End position in input
 * @return t_ast_node* Root node of the AST
 */
static t_ast_node	*build_ast(t_shell_bonus *shell_bonus, char *input,
							int start, int end)
{
	int			op_pos;
	char		*cmd_str;
	t_command	*cmd;
	t_ast_node	*node;

	if (start >= end)
		return (NULL);
	op_pos = find_operator(input, start, "||");
	if (op_pos != -1 && op_pos < end)
	{
		node = create_ast_node(NULL, OP_OR);
		node->left = build_ast(shell_bonus, input, start, op_pos);
		node->right = build_ast(shell_bonus, input, op_pos + 2, end);
		return (node);
	}
	op_pos = find_operator(input, start, "&&");
	if (op_pos != -1 && op_pos < end)
	{
		node = create_ast_node(NULL, OP_AND);
		node->left = build_ast(shell_bonus, input, start, op_pos);
		node->right = build_ast(shell_bonus, input, op_pos + 2, end);
		return (node);
	}
	cmd_str = ft_substr(input, start, end - start);
	if (!cmd_str)
		return (NULL);
	cmd = create_command();
	if (!cmd)
	{
		free(cmd_str);
		return (NULL);
	}
	if (parse_input(&shell_bonus->base, cmd_str) == SUCCESS)
	{
		free(cmd_str);
		return (create_ast_node(shell_bonus->base.commands, OP_NONE));
	}
	free(cmd_str);
	free(cmd);
	return (NULL);
}

/**
 * @brief Execute AST
 * 
 * @param node Current AST node
 * @param shell_bonus Shell bonus structure
 * @return int Command exit status
 */
int	execute_ast(t_ast_node *node, t_shell_bonus *shell_bonus)
{
	int	status;

	if (!node)
		return (0);
	if (node->op == OP_NONE)
	{
		shell_bonus->base.commands = node->cmd;
		status = execute_commands(&shell_bonus->base);
		shell_bonus->base.commands = NULL;
		return (status);
	}
	else if (node->op == OP_AND)
	{
		status = execute_ast(node->left, shell_bonus);
		if (status == 0)
			return (execute_ast(node->right, shell_bonus));
		return (status);
	}
	else if (node->op == OP_OR)
	{
		status = execute_ast(node->left, shell_bonus);
		if (status != 0)
			return (execute_ast(node->right, shell_bonus));
		return (status);
	}
	return (0);
}

/**
 * @brief Parse operators in input
 * 
 * @param shell_bonus Shell bonus structure
 * @param input Input string
 * @return int SUCCESS on success, ERROR on error
 */
int	parse_operators(t_shell_bonus *shell_bonus, char *input)
{
	if (!input || !*input)
		return (ERROR);
	if (check_quotes(input) == ERROR)
	{
		print_error(NULL, NULL, "unclosed quotes");
		return (ERROR);
	}
	shell_bonus->ast_root = build_ast(shell_bonus, input, 0, ft_strlen(input));
	if (!shell_bonus->ast_root)
		return (ERROR);
	return (SUCCESS);
}
