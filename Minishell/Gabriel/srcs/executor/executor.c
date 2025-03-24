/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <vigde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 12:17:28 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/03/03 12:17:31 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Execute a builtin command
 * 
 * @param cmd Command structure
 * @param shell The shell structure
 * @return int Command exit status
 */
static int	execute_builtin(t_command *cmd, t_shell *shell)
{
	if (ft_strncmp(cmd->cmd, "echo", ft_strlen("echo")) == 0)
		return (builtin_echo(cmd->args));
	else if (ft_strncmp(cmd->cmd, "cd", ft_strlen("cd")) == 0)
		return (builtin_cd(cmd->args, shell));
	else if (ft_strncmp(cmd->cmd, "pwd", ft_strlen("pwd")) == 0)
		return (builtin_exit(cmd->args, shell));
	else if (ft_strncmp(cmd->cmd, "export", ft_strlen("export")) == 0)
		return (builtin_export(cmd->args, shell));
	else if (ft_strncmp(cmd->cmd, "unset", ft_strlen("unset")) == 0)
		return (builtin_unset(cmd->args, shell));
	else if (ft_strncmp(cmd->cmd, "env", ft_strlen("env")) == 0)
		return (builtin_exit(cmd->args, shell));
	else if (ft_strncmp(cmd->cmd, "exit", ft_strlen("exit")) == 0)
		return (builtin_exit(cmd->args, shell));
	return (ERROR);
}

/**
 * @brief Execute child process
 * 
 * @param cmd Command structure
 * @param shell The shell structure
 * @return int Never returns (exits process)
 */
static int	execute_child(t_command *cmd, t_shell *shell)
{
	char	*path;

	setup_io(cmd, shell);
	if (!cmd->cmd)
		exit(EXIT_SUCCESS);
	if (is_builtin(cmd->cmd))
	{
		exit(execute_builtin(cmd, shell));
	}
	else
	{
		path = find_command_path(cmd->cmd, shell->env);
		if (!path)
		{
			print_error(cmd->cmd, NULL, "command not found");
			exit(127);
		}
		if (execve(path, cmd->args, shell->env) == -1)
		{
			print_error(cmd->cmd, NULL, strerror(errno));
			exit(126);
		}
	}
	return (EXIT_FAILURE);
}

/**
 * @brief Execute a command
 * 
 * @param cmd Command structure
 * @param shell The shell structure
 * @return int SUCCESS on success, ERROR on error
 */
int	execute_command(t_command *cmd, t_shell *shell)
{
	pid_t	pid;
	int		status;

	if (!cmd->next && is_builtin(cmd->cmd))
	{
		setup_redirections(cmd, shell);
		status = execute_builtin(cmd, shell);
		reset_redirections(shell);
		return (status);
	}
	if (setup_pipes(cmd) == ERROR)
		return (ERROR);
	pid = fork();
	if (pid == -1)
		return (ERROR);
	if (pid == 0)
		execute_child(cmd, shell);
	cmd->pid = pid;
	close_pipes(cmd);
	return (SUCCESS);
}

/**
 * @brief Wait for commands to finish
 * 
 * @param shell The shell structure
 * @return int Last command exit status
 */
int	wait_commands(t_shell *shell)
{
	t_command	*cmd;
	int			status;
	int			result;

	cmd = shell->commands;
	result = 0;
	while (cmd)
	{
		if (cmd->pid > 0)
		{
			waitpid(cmd->pid, &status, 0);
			if (WIFEXITED(status))
				result = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				result = WTERMSIG(status) + 128;
		}
		cmd = cmd->next;
	}
	return (result);
}

/**
 * @brief Execute all commands
 * 
 * @param shell The shell structure
 * @return int Last command exit status
 */
int	execute_commands(t_shell *shell)
{
	t_command	*cmd;
	int			status;

	if (!shell->commands)
		return (SUCCESS);
	cmd = shell->commands;
	while (cmd)
	{
		status = execute_command(cmd, shell);
		if (status != SUCCESS && !cmd->next)
			return (status);
		cmd = cmd->next;
	}
	status = wait_commands(shell);
	shell->exit_status = status;
	return (status);
}
