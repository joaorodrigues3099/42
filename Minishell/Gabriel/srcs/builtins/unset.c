/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <vigde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 12:17:28 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/03/03 12:17:31 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Remove an environment variable
 * 
 * @param var Variable name to remove
 * @param shell The shell structure
 */
void	remove_env_var(char *var, t_shell *shell)
{
	int		i;
	int		j;
	int		len;
	char	**new_env;

	i = 0;
	while (shell->env[i])
		i++;
	new_env = (char **)malloc(sizeof(char *) * (i + 1));
	if (!new_env)
		return ;
	i = 0;
	j = 0;
	len = ft_strlen(var);
	while (shell->env[i])
	{
		if (ft_strncmp(shell->env[i], var, len) != 0
			|| (shell->env[i][len] != '=' && shell->env[i][len] != '\0'))
			new_env[j++] = ft_strdup(shell->env[i]);
		i++;
	}
	new_env[j] = NULL;
	free_array(shell->env);
	shell->env = new_env;
}

/**
 * @brief Implements the unset builtin command
 * 
 * @param args Command arguments
 * @param shell The shell structure
 * @return int SUCCESS on success, ERROR on error
 */
int	builtin_unset(char **args, t_shell *shell)
{
	int	i;
	int	status;

	if (!args[1])
		return (SUCCESS);
	status = SUCCESS;
	i = 1;
	while (args[i])
	{
		if (!is_valid_identifier(args[i]))
		{
			print_error("unset", args[i], "not a valid identifier");
			status = ERROR;
		}
		else
			remove_env_var(args[i], shell);
		i++;
	}
	return (status);
}