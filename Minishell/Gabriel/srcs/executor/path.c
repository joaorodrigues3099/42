/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <vigde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 12:17:28 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/03/03 12:17:31 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Check if a path is a directory
 * 
 * @param path Path to check
 * @return int 1 if directory, 0 otherwise
 */
int	is_directory(char *path)
{
	struct stat	s;

	if (stat(path, &s) == 0)
	{
		if (S_ISDIR(s.st_mode))
			return (1);
	}
	return (0);
}

/**
 * @brief Check if a path is executable
 * 
 * @param path Path to check
 * @return int 1 if executable, 0 otherwise
 */
int	is_executable(char *path)
{
	if (access(path, F_OK) == 0)
	{
		if (access(path, X_OK) == 0)
			return (1);
		print_error(path, NULL, "Permission denied");
		return (0);
	}
	return (0);
}

/**
 * @brief Find command path in PATH environment variable
 * 
 * @param cmd Command name
 * @param env Environment variables
 * @return char* Command path or NULL if not found
 */
char	*find_command_path(char *cmd, char **env)
{
	char	*path_var;
	char	**paths;
	char	*path;
	char	*tmp;
	int		i;

	if (!cmd || !*cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
	{
		if (is_executable(cmd))
			return (ft_strdup(cmd));
		return (NULL);
	}
	path_var = get_env_value("PATH", env);
	if (!path_var)
		return (NULL);
	paths = ft_split(path_var, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (is_executable(path))
		{
			free_array(paths);
			return (path);
		}
		free(path);
		i++;
	}
	free_array(paths);
	return (NULL);
}
