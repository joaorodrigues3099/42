/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <vigde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 12:17:28 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/03/03 12:17:31 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_BONUS_H
# define MINISHELL_BONUS_H

# include "minishell.h"

typedef enum e_operator
{
	OP_NONE,
	OP_AND,
	OP_OR
}	t_operator;

typedef struct s_ast_node
{
	t_command			*cmd;
	t_operator			op;
	struct s_ast_node	*left;
	struct s_ast_node	*right;
}	t_ast_node;

typedef struct s_shell_bonus
{
	t_shell		base;
	t_ast_node	*ast_root;
}	t_shell_bonus;

// operators_bonus.c
int			parse_operators(t_shell_bonus *shell, char *input);
t_ast_node	*create_ast_node(t_command *cmd, t_operator op);
void		free_ast(t_ast_node *root);
int			execute_ast(t_ast_node *node, t_shell_bonus *shell);

// wildcard_bonus.c
char		**expand_wildcards(char *pattern);
int			match_wildcard(char *pattern, char *str);
void		apply_wildcards(t_command *cmd);

#endif
