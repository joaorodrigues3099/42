/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <vigde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 12:17:28 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/03/03 12:17:31 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Initialize shell structure
 * 
 * @param shell The shell structure to initialize
 * @param envp Environment variables
 * @return int SUCCESS on success, ERROR on error
 */
int	init_shell(t_shell *shell, char **envp)
{
	shell->env = copy_env(envp);
	if (!shell->env)
		return (ERROR);
	shell->commands = NULL;
	shell->tokens = NULL;
	shell->exit_status = 0;
	shell->in_fd = STDIN_FILENO;
	shell->out_fd = STDOUT_FILENO;
	return (SUCCESS);
}

/**
 * @brief Clean up shell structure for next command
 * 
 * @param shell The shell structure to clean up
 */
void	cleanup_shell(t_shell *shell)
{
	free_tokens(shell->tokens);
	free_commands(shell->commands);
	shell->tokens = NULL;
	shell->commands = NULL;
	if (shell->in_fd != STDIN_FILENO)
		close(shell->in_fd);
	if (shell->out_fd != STDOUT_FILENO)
		close(shell->out_fd);
	shell->in_fd = STDIN_FILENO;
	shell->out_fd = STDOUT_FILENO;
}

/**
 * @brief Free all resources in shell structure
 * 
 * @param shell The shell structure to free
 */
void	free_shell(t_shell *shell)
{
	cleanup_shell(shell);
	free_array(shell->env);
}
