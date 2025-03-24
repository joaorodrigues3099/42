/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <vigde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 12:17:28 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/03/03 12:17:31 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Implements the pwd builtin command
 * 
 * @return int SUCCESS on success, ERROR on error
 */
int	builtin_pwd(void)
{
	char	cwd[PATH_MAX];

	if (!getcwd(cwd, PATH_MAX))
	{
		print_error("pwd", NULL, strerror(errno));
		return (ERROR);
	}
	printf("%s\n", cwd);
	return (SUCCESS);
}
