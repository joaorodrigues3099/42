/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <vigde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 12:17:28 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/03/03 12:17:31 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Check if a string is a valid environment variable identifier
 * 
 * @param str String to check
 * @return int 1 if valid, 0 otherwise
 */
int	is_valid_identifier(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (0);
	i = 1;
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief Sort environment variables alphabetically
 * 
 * @param env Environment variables array
 */
void	sort_env(char **env)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (env[i])
	{
		j = i + 1;
		while (env[j])
		{
			if (ft_strncmp(env[i], env[j], ft_strlen(env[i])) > 0)
			{
				temp = env[i];
				env[i] = env[j];
				env[j] = temp;
			}
			j++;
		}
		i++;
	}
}

/**
 * @brief Print environment variables in export format
 * 
 * @param env Environment variables array
 */
void	print_sorted_env(char **env)
{
	int		i;
	//int		j;
	char	**sorted_env;
	char	*equal_sign;

	i = 0;
	while (env[i])
		i++;
	sorted_env = (char **)malloc(sizeof(char *) * (i + 1));
	if (!sorted_env)
		return ;
	i = 0;
	while (env[i])
	{
		sorted_env[i] = ft_strdup(env[i]);
		i++;
	}
	sorted_env[i] = NULL;
	sort_env(sorted_env);
	i = 0;
	while (sorted_env[i])
	{
		printf("declare -x ");
		equal_sign = ft_strchr(sorted_env[i], '=');
		if (equal_sign)
		{
			*equal_sign = '\0';
			printf("%s=\"%s\"", sorted_env[i], equal_sign + 1);
		}
		else
			printf("%s", sorted_env[i]);
		printf("\n");
		free(sorted_env[i]);
		i++;
	}
	free(sorted_env);
}

/**
 * @brief Process export argument
 * 
 * @param arg Argument to process
 * @param shell The shell structure
 * @return int SUCCESS on success, ERROR on error
 */
static int	process_export_arg(char *arg, t_shell *shell)
{
	char	*equal_sign;
	char	*var_name;
	char	*var_value;
	int		result;

	if (!is_valid_identifier(arg))
	{
		print_error("export", arg, "not a valid identifier");
		return (ERROR);
	}
	equal_sign = ft_strchr(arg, '=');
	if (equal_sign)
	{
		*equal_sign = '\0';
		var_name = arg;
		var_value = equal_sign + 1;
		result = update_env_var(var_name, var_value, shell);
		*equal_sign = '=';
		return (result);
	}
	return (SUCCESS);
}

/**
 * @brief Implements the export builtin command
 * 
 * @param args Command arguments
 * @param shell The shell structure
 * @return int SUCCESS on success, ERROR on error
 */
int	builtin_export(char **args, t_shell *shell)
{
	int	i;
	int	status;

	if (!args[1])
	{
		print_sorted_env(shell->env);
		return (SUCCESS);
	}
	status = SUCCESS;
	i = 1;
	while (args[i])
	{
		if (process_export_arg(args[i], shell) == ERROR)
			status = ERROR;
		i++;
	}
	return (status);
}
