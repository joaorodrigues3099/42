/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <vigde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 12:17:28 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/03/03 12:17:31 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

/**
 * @brief Match a string with a wildcard pattern
 * 
 * @param pattern Pattern with * wildcard
 * @param str String to match
 * @return int 1 if matches, 0 otherwise
 */
int	match_wildcard(char *pattern, char *str)
{
	if (*pattern == '\0' && *str == '\0')
		return (1);
	if (*pattern == '*' && *(pattern + 1) != '\0' && *str == '\0')
		return (0);
	if (*pattern == '*')
		return (match_wildcard(pattern + 1, str) || match_wildcard(pattern, str + 1));
	if (*pattern == *str)
		return (match_wildcard(pattern + 1, str + 1));
	return (0);
}

/**
 * @brief Count matches for a wildcard pattern
 * 
 * @param pattern Pattern with * wildcard
 * @return int Number of matches
 */
static int	count_matches(char *pattern)
{
	DIR				*dir;
	struct dirent	*entry;
	int				count;

	count = 0;
	dir = opendir(".");
	if (!dir)
		return (0);
	while ((entry = readdir(dir)) != NULL)
	{
		if (entry->d_name[0] != '.' || pattern[0] == '.')
		{
			if (match_wildcard(pattern, entry->d_name))
				count++;
		}
	}
	closedir(dir);
	return (count);
}

/**
 * @brief Expand wildcard pattern
 * 
 * @param pattern Pattern with * wildcard
 * @return char** Array of matching strings
 */
char	**expand_wildcards(char *pattern)
{
	DIR				*dir;
	struct dirent	*entry;
	char			**result;
	int				count;
	int				i;

	if (!ft_strchr(pattern, '*'))
	{
		result = (char **)malloc(sizeof(char *) * 2);
		result[0] = ft_strdup(pattern);
		result[1] = NULL;
		return (result);
	}
	count = count_matches(pattern);
	if (count == 0)
	{
		result = (char **)malloc(sizeof(char *) * 2);
		result[0] = ft_strdup(pattern);
		result[1] = NULL;
		return (result);
	}
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	dir = opendir(".");
	if (!dir)
	{
		free(result);
		return (NULL);
	}
	i = 0;
	while ((entry = readdir(dir)) != NULL)
	{
		if (entry->d_name[0] != '.' || pattern[0] == '.')
		{
			if (match_wildcard(pattern, entry->d_name))
				result[i++] = ft_strdup(entry->d_name);
		}
	}
	result[i] = NULL;
	closedir(dir);
	return (result);
}

/**
 * @brief Apply wildcard expansion to command arguments
 * 
 * @param cmd Command structure
 */
void	apply_wildcards(t_command *cmd)
{
	int		i;
	int		j;
	int		new_argc;
	char	**new_args;
	char	**expanded;

	if (!cmd || !cmd->args)
		return ;
	new_argc = 0;
	for (i = 0; cmd->args[i]; i++)
	{
		expanded = expand_wildcards(cmd->args[i]);
		for (j = 0; expanded[j]; j++)
			new_argc++;
		free_array(expanded);
	}
	new_args = (char **)malloc(sizeof(char *) * (new_argc + 1));
	if (!new_args)
		return ;
	new_argc = 0;
	for (i = 0; cmd->args[i]; i++)
	{
		expanded = expand_wildcards(cmd->args[i]);
		for (j = 0; expanded[j]; j++)
			new_args[new_argc++] = ft_strdup(expanded[j]);
		free_array(expanded);
	}
	new_args[new_argc] = NULL;
	free_array(cmd->args);
	cmd->args = new_args;
	if (cmd->cmd)
		free(cmd->cmd);
	if (new_args[0])
		cmd->cmd = ft_strdup(new_args[0]);
}
