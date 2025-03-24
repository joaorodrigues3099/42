/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <vigde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 12:17:28 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/03/03 12:17:31 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Check if a string is the -n option
 * 
 * @param str The string to check
 * @return int 1 if it's the -n option, 0 otherwise
 */
int	has_n_option(char *str)
{
	int	i;

	if (!str || str[0] != '-' || str[1] != 'n')
		return (0);
	i = 2;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief Implements the echo builtin command
 * 
 * @param args Command arguments
 * @return int SUCCESS on success, ERROR on error
 */
int	builtin_echo(char **args)
{
	int	i;
	int	newline;

	if (!args[1])
	{
		printf("\n");
		return (SUCCESS);
	}
	newline = 1;
	i = 1;
	while (args[i] && has_n_option(args[i]))
	{
		newline = 0;
		i++;
	}
	while (args[i])
	{
		printf("%s", args[i]);
		if (args[i + 1])
			printf(" ");
		i++;
	}
	if (newline)
		printf("\n");
	return (SUCCESS);
}
