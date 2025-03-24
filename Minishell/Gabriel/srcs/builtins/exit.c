/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <vigde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 12:17:28 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/03/03 12:17:31 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Check if a string is numeric
 * 
 * @param str String to check
 * @return int 1 if numeric, 0 otherwise
 */
int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief Implements the exit builtin command
 * 
 * @param args Command arguments
 * @param shell The shell structure
 * @return int Never returns (exits the program)
 */
int	builtin_exit(char **args, t_shell *shell)
{
	int	exit_code;

	printf("exit\n");
	if (!args[1])
		exit_code = shell->exit_status;
	else if (!is_numeric(args[1]))
	{
		print_error("exit", args[1], "numeric argument required");
		exit_code = 255;
	}
	else if (args[2])
	{
		print_error("exit", NULL, "too many arguments");
		return (ERROR);
	}
	else
		exit_code = ft_atoi(args[1]) % 256;
	free_shell(shell);
	exit(exit_code);
	return (SUCCESS);
}
