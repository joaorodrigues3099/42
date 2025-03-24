/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <vigde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 12:17:28 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/03/03 12:17:31 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Update PWD and OLDPWD environment variables
 * 
 * @param shell The shell structure
 * @return int SUCCESS on success, ERROR on error
 */
int	update_pwd_env(t_shell *shell)
{
	char	cwd[PATH_MAX];
	char	*old_pwd;

	old_pwd = get_env_value("PWD", shell->env);
	if (old_pwd)
		update_env_var("OLDPWD", old_pwd, shell);
	if (getcwd(cwd, PATH_MAX))
		update_env_var("PWD", cwd, shell);
	else
		return (ERROR);
	return (SUCCESS);
}

/**
 * @brief Change current directory
 * 
 * @param path Path to change to
 * @param shell The shell structure
 * @return int SUCCESS on success, ERROR on error
 */
int	change_directory(char *path, t_shell *shell)
{
	char	*home;

	if (!path || !*path)
	{
		home = get_env_value("HOME", shell->env);
		if (!home)
		{
			print_error("cd", NULL, "HOME not set");
			return (ERROR);
		}
		path = home;
	}
	if (chdir(path) != 0)
	{
		print_error("cd", path, strerror(errno));
		return (ERROR);
	}
	return (update_pwd_env(shell));
}

/**
 * @brief Implements the cd builtin command
 * 
 * @param args Command arguments
 * @param shell The shell structure
 * @return int SUCCESS on success, ERROR on error
 */
int	builtin_cd(char **args, t_shell *shell)
{
	if (!args[1])
		return (change_directory(NULL, shell));
	return (change_directory(args[1], shell));
}

