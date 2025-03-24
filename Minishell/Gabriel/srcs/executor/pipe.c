/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <vigde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 12:17:28 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/03/03 12:17:31 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Setup pipes for commands
 * 
 * @param cmd Command structure
 * @return int SUCCESS on success, ERROR on error
 */
int	setup_pipes(t_command *cmd)
{
	if (cmd->next && pipe(cmd->pipe_fd) == -1)
	{
		print_error(NULL, NULL, "pipe error");
		return (ERROR);
	}
	return (SUCCESS);
}

/**
 * @brief Close pipes for command
 * 
 * @param cmd Command structure
 */
void	close_pipes(t_command *cmd)
{
	if (cmd->pipe_fd[0] != -1)
		close(cmd->pipe_fd[0]);
	if (cmd->pipe_fd[1] != -1)
		close(cmd->pipe_fd[1]);
	cmd->pipe_fd[0] = -1;
	cmd->pipe_fd[1] = -1;
}

/**
 * @brief Setup I/O for command
 * 
 * @param cmd Command structure
 * @param shell The shell structure
 */
void	setup_io(t_command *cmd, t_shell *shell)
{
	t_command	*prev;

	prev = shell->commands;
	while (prev && prev->next != cmd)
		prev = prev->next;
	
	if (prev && prev->pipe_fd[0] != -1)
	{
		dup2(prev->pipe_fd[0], STDIN_FILENO);
		close_pipes(prev);
	}
	else if (shell->in_fd != STDIN_FILENO)
	{
		dup2(shell->in_fd, STDIN_FILENO);
		close(shell->in_fd);
	}
	
	if (cmd->pipe_fd[1] != -1)
	{
		dup2(cmd->pipe_fd[1], STDOUT_FILENO);
		close_pipes(cmd);
	}
	else if (shell->out_fd != STDOUT_FILENO)
	{
		dup2(shell->out_fd, STDOUT_FILENO);
		close(shell->out_fd);
	}
}
