/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <vigde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 12:17:28 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/03/03 12:17:31 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h" 

/**
 * @brief Add a redirection to a command
 * 
 * @param cmd Command structure
 * @param type Redirection type
 * @param file Redirection file
 * @return int SUCCESS on success, ERROR on error
 */
int	add_redirection(t_command *cmd, int type, char *file)
{
	t_redirect	*new_redir;
	t_redirect	*tmp;

	new_redir = (t_redirect *)malloc(sizeof(t_redirect));
	if (!new_redir)
		return (ERROR);
	new_redir->type = type;
	new_redir->file = file;
	new_redir->next = NULL;
	if (!cmd->redirects)
	{
		cmd->redirects = new_redir;
		return (SUCCESS);
	}
	tmp = cmd->redirects;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_redir;
	return (SUCCESS);
}

/**
 * @brief Setup input redirection
 * 
 * @param redir Redirection structure
 * @param shell The shell structure
 * @return int SUCCESS on success, ERROR on error
 */
static int	setup_input_redirection(t_redirect *redir, t_shell *shell)
{
	int	fd;

	if (shell->in_fd != STDIN_FILENO)
		close(shell->in_fd);
	fd = open(redir->file, O_RDONLY);
	if (fd == -1)
	{
		print_error(NULL, redir->file, strerror(errno));
		return (ERROR);
	}
	shell->in_fd = fd;
	return (SUCCESS);
}

/**
 * @brief Setup output redirection
 * 
 * @param redir Redirection structure
 * @param shell The shell structure
 * @return int SUCCESS on success, ERROR on error
 */
static int	setup_output_redirection(t_redirect *redir, t_shell *shell)
{
	int	fd;
	int	flags;

	if (shell->out_fd != STDOUT_FILENO)
		close(shell->out_fd);
	if (redir->type == TOKEN_REDIR_OUT)
		flags = O_WRONLY | O_CREAT | O_TRUNC;
	else
		flags = O_WRONLY | O_CREAT | O_APPEND;
	fd = open(redir->file, flags, 0644);
	if (fd == -1)
	{
		print_error(NULL, redir->file, strerror(errno));
		return (ERROR);
	}
	shell->out_fd = fd;
	return (SUCCESS);
}

/**
 * @brief Setup heredoc
 * 
 * @param redir Redirection structure
 * @param shell The shell structure
 * @return int SUCCESS on success, ERROR on error
 */
static int	setup_heredoc(t_redirect *redir, t_shell *shell)
{
	int		pipe_fd[2];
	char	*line;

	if (shell->in_fd != STDIN_FILENO)
		close(shell->in_fd);
	if (pipe(pipe_fd) == -1)
		return (ERROR);
	while (1)
	{
		line = readline("> ");
		if (!line || ft_strncmp(line, redir->file, ft_strlen(redir->file) + 1) == 0)
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, pipe_fd[1]);
		free(line);
	}
	close(pipe_fd[1]);
	shell->in_fd = pipe_fd[0];
	return (SUCCESS);
}

/**
 * @brief Setup redirections for a command
 * 
 * @param cmd Command structure
 * @param shell The shell structure
 * @return int SUCCESS on success, ERROR on error
 */
int	setup_redirections(t_command *cmd, t_shell *shell)
{
	t_redirect	*redir;

	redir = cmd->redirects;
	while (redir)
	{
		if (redir->type == TOKEN_REDIR_IN)
		{
			if (setup_input_redirection(redir, shell) == ERROR)
				return (ERROR);
		}
		else if (redir->type == TOKEN_REDIR_OUT || redir->type == TOKEN_REDIR_APPEND)
		{
			if (setup_output_redirection(redir, shell) == ERROR)
				return (ERROR);
		}
		else if (redir->type == TOKEN_HEREDOC)
		{
			if (setup_heredoc(redir, shell) == ERROR)
				return (ERROR);
		}
		redir = redir->next;
	}
	return (SUCCESS);
}

/**
 * @brief Reset redirections
 * 
 * @param shell The shell structure
 */
void	reset_redirections(t_shell *shell)
{
	if (shell->in_fd != STDIN_FILENO)
	{
		close(shell->in_fd);
		shell->in_fd = STDIN_FILENO;
	}
	if (shell->out_fd != STDOUT_FILENO)
	{
		close(shell->out_fd);
		shell->out_fd = STDOUT_FILENO;
	}
}

/**
 * @brief Handle all redirections
 * 
 * @param shell The shell structure
 * @return int SUCCESS on success, ERROR on error
 */
int	handle_redirections(t_shell *shell)
{
	t_command	*cmd;

	cmd = shell->commands;
	while (cmd)
	{
		if (cmd->redirects)
		{
			if (setup_redirections(cmd, shell) == ERROR)
				return (ERROR);
		}
		cmd = cmd->next;
	}
	return (SUCCESS);
}
