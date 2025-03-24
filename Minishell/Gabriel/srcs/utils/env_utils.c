/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <vigde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 12:17:28 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/03/03 12:17:31 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Copy environment variables
 * 
 * @param envp Environment variables to copy
 * @return char** Copied environment variables
 */
char	**copy_env(char **envp)
{
	char	**env;
	int		i;

	i = 0;
	while (envp[i])
		i++;
	env = (char **)malloc(sizeof(char *) * (i + 1));
	if (!env)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		env[i] = ft_strdup(envp[i]);
		if (!env[i])
		{
			free_array(env);
			return (NULL);
		}
		i++;
	}
	env[i] = NULL;
	return (env);
}

/**
 * @brief Get environment variable value
 * 
 * @param var Variable name
 * @param env Environment variables
 * @return char* Variable value or NULL if not found
 */
char	*get_env_value(char *var, char **env)
{
	int		i;
	int		len;
	char	*value;

	i = 0;
	len = ft_strlen(var);
	while (env[i])
	{
		if (ft_strncmp(env[i], var, len) == 0 && env[i][len] == '=')
		{
			value = env[i] + len + 1;
			return (value);
		}
		i++;
	}
	return (NULL);
}

/**
 * @brief Add environment variable
 * 
 * @param var Variable name
 * @param value Variable value
 * @param shell The shell structure
 * @return int SUCCESS on success, ERROR on error
 */
int	add_env_var(char *var, char *value, t_shell *shell)
{
	int		i;
	int		j;
	char	**new_env;
	char	*new_var;

	i = 0;
	while (shell->env[i])
		i++;
	new_env = (char **)malloc(sizeof(char *) * (i + 2));
	if (!new_env)
		return (ERROR);
	j = 0;
	while (shell->env[j])
	{
		new_env[j] = ft_strdup(shell->env[j]);
		j++;
	}
	new_var = ft_strjoin(var, "=");
	new_env[j] = ft_strjoin(new_var, value);
	new_env[j + 1] = NULL;
	free(new_var);
	free_array(shell->env);
	shell->env = new_env;
	return (SUCCESS);
}

/**
 * @brief Update environment variable
 * 
 * @param var Variable name
 * @param value Variable value
 * @param shell The shell structure
 * @return int SUCCESS on success, ERROR on error
 */
int	update_env_var(char *var, char *value, t_shell *shell)
{
	int		i;
	int		len;
	char	*new_var;
	char	*tmp;

	i = 0;
	len = ft_strlen(var);
	while (shell->env[i])
	{
		if (ft_strncmp(shell->env[i], var, len) == 0 && shell->env[i][len] == '=')
		{
			free(shell->env[i]);
			new_var = ft_strjoin(var, "=");
			if (!new_var)
				return (ERROR);
			tmp = ft_strjoin(new_var, value);
			free(new_var);
			if (!tmp)
				return (ERROR);
			shell->env[i] = tmp;
			return (SUCCESS);
		}
		i++;
	}
	return (add_env_var(var, value, shell));
}

/**
 * @brief Check if command is a builtin
 * 
 * @param cmd Command name
 * @return int 1 if builtin, 0 otherwise
 */
int	is_builtin(const char *cmd)
{
	if (!cmd)
		return (0);
	if (ft_strncmp(cmd, "echo",5) == 0)
		return (1);
	if (ft_strncmp(cmd, "cd",3) == 0)
		return (1);
	if (ft_strncmp(cmd, "pwd",4) == 0)
		return (1);
	if (ft_strncmp(cmd, "export",7) == 0)
		return (1);
	if (ft_strncmp(cmd, "unset",6) == 0)
		return (1);
	if (ft_strncmp(cmd, "env",4) == 0)
		return (1);
	if (ft_strncmp(cmd, "exit",5) == 0)
		return (1);
	return (0);
}
