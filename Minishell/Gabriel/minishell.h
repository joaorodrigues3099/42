/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <vigde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 12:17:28 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/03/03 12:17:31 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>
# include <limits.h>

# define SUCCESS 0
# define ERROR 1
# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

extern int	g_signal;

typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIR_IN,
	TOKEN_REDIR_OUT,
	TOKEN_REDIR_APPEND,
	TOKEN_HEREDOC,
	TOKEN_EOF
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
	struct s_token	*next;
}	t_token;

typedef struct s_redirect
{
	int					type;
	char				*file;
	struct s_redirect	*next;
}	t_redirect;

typedef struct s_command
{
	char				*cmd;
	char				**args;
	t_redirect			*redirects;
	struct s_command	*next;
	int					pipe_fd[2];
	pid_t				pid;
}	t_command;

typedef struct s_shell
{
	char		**env;
	t_command	*commands;
	t_token		*tokens;
	int			exit_status;
	int			in_fd;
	int			out_fd;
}	t_shell;

// main.c
int			main(int argc, char **argv, char **envp);

// init.c
int			init_shell(t_shell *shell, char **envp);
void		cleanup_shell(t_shell *shell);
void		free_shell(t_shell *shell);

// parser/lexer.c
int			lexer(t_shell *shell, char *input);
t_token		*create_token(t_token_type type, char *value);
void		add_token(t_token **tokens, t_token *new_token);
void		free_tokens(t_token *tokens);

// parser/parser.c
int			parse_input(t_shell *shell, char *input);
t_command	*create_command(void);
void		add_command(t_command **commands, t_command *new_cmd);
int			parse_tokens(t_shell *shell);

// parser/quotes.c
char		*remove_quotes(char *str);
int			is_quoted(char *str, int index);
int			check_quotes(char *input);
char		*handle_quotes(char *str, t_shell *shell);

// parser/redirect.c
int			handle_redirections(t_shell *shell);
int			add_redirection(t_command *cmd, int type, char *file);
int			setup_redirections(t_command *cmd, t_shell *shell);
void		reset_redirections(t_shell *shell);

// parser/tokens.c
int			is_delimiter(char c);
int			is_space(char c);
int			get_token_type(char *str);
char		*get_token_value(char *str, int *i);

// signals/signals.c
void		setup_signals(void);
void		handle_sigint(int sig);
void		handle_sigquit(int sig);
void		reset_signals(void);

// executor/executor.c
int			execute_commands(t_shell *shell);
int			execute_command(t_command *cmd, t_shell *shell);
int			wait_commands(t_shell *shell);

// executor/path.c
char		*find_command_path(char *cmd, char **env);
int			is_executable(char *path);
int			is_directory(char *path);

// executor/pipe.c
int			setup_pipes(t_command *cmd);
void		close_pipes(t_command *cmd);
void		setup_io(t_command *cmd, t_shell *shell);

// builtins/cd.c
int			builtin_cd(char **args, t_shell *shell);
int			change_directory(char *path, t_shell *shell);
int			update_pwd_env(t_shell *shell);

// builtins/echo.c
int			builtin_echo(char **args);
int			has_n_option(char *str);

// builtins/env.c
int			builtin_env(t_shell *shell);

// builtins/exit.c
int			builtin_exit(char **args, t_shell *shell);
int			is_numeric(char *str);

// builtins/export.c
int			builtin_export(char **args, t_shell *shell);
int			is_valid_identifier(char *str);
void		sort_env(char **env);
void		print_sorted_env(char **env);

// builtins/pwd.c
int			builtin_pwd(void);

// builtins/unset.c
int			builtin_unset(char **args, t_shell *shell);
void		remove_env_var(char *var, t_shell *shell);

// utils/env_utils.c
char		**copy_env(char **envp);
char		*get_env_value(char *var, char **env);
int			add_env_var(char *var, char *value, t_shell *shell);
int			update_env_var(char *var, char *value, t_shell *shell);
int			is_builtin(const char *cmd);

// utils/error.c
void		print_error(char *cmd, char *arg, char *msg);
void		syntax_error(char *token);
int			error_return(char *msg, int ret);

// utils/free.c
void		free_commands(t_command *commands);
void		free_redirects(t_redirect *redirects);
void		free_array(char **array);

#endif
