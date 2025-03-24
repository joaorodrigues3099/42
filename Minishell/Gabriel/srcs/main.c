/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <vigde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 12:17:28 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/03/03 12:17:31 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	g_signal;

/**
 * @brief Display prompt and read line
 * 
 * @return char* The line read or NULL if EOF (ctrl-D)
 */
static char	*get_input(void)
{
	char	*line;

	line = readline("minishell$ ");
	if (line && *line)
		add_history(line);
	return (line);
}

/**
 * @brief Main loop of the shell
 * 
 * @param shell The shell structure
 * @return int EXIT_SUCCESS on success, EXIT_FAILURE on error
 */
static int	shell_loop(t_shell *shell)
{
	char	*line;

	while (1)
	{
		g_signal = 0;
		setup_signals();
		line = get_input();
		if (!line)
			break ;
		if (*line)
		{
			if (parse_input(shell, line) == SUCCESS)
				execute_commands(shell);
			cleanup_shell(shell);
		}
		free(line);
	}
	printf("exit\n");
	return (EXIT_SUCCESS);
}

/**
 * @brief Main function
 * 
 * @param argc Argument count
 * @param argv Argument vector
 * @param envp Environment variables
 * @return int EXIT_SUCCESS on success, EXIT_FAILURE on error
 */
int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;
	int		ret;

	(void)argc;
	(void)argv;
	if (init_shell(&shell, envp) != SUCCESS)
		return (EXIT_FAILURE);
	ret = shell_loop(&shell);
	free_shell(&shell);
	return (ret);
}

