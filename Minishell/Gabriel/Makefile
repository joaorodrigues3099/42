# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vigde-ol <vigde-ol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/03 12:17:28 by vigde-ol          #+#    #+#              #
#    Updated: 2024/03/03 12:17:31 by vigde-ol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nome do executável
NAME = minishell

# Compilador e flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# Diretório da libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Flags para readline
READLINE = -lreadline -L/usr/include -L/usr/lib -I/usr/include -I/usr/lib

# Diretórios de código-fonte
SRC_DIR = srcs
BUILTINS_DIR = $(SRC_DIR)/builtins
EXECUTOR_DIR = $(SRC_DIR)/executor
PARSER_DIR = $(SRC_DIR)/parser
SIGNALS_DIR = $(SRC_DIR)/signals
UTILS_DIR = $(SRC_DIR)/utils
BONUS_DIR = srcs_bonus

# Encontrar automaticamente todos os arquivos .c dentro das pastas
SRCS = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(BUILTINS_DIR)/*.c) $(wildcard $(EXECUTOR_DIR)/*.c) $(wildcard $(PARSER_DIR)/*.c) $(wildcard $(SIGNALS_DIR)/*.c) $(wildcard $(UTILS_DIR)/*.c)

BONUS_SRCS = $(wildcard $(BONUS_DIR)/*.c)

# Transformação de .c para .o
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# Diretórios de includes
INCS = -I./includes -I./$(LIBFT_DIR) -I/usr/include/readline

# Regra padrão
all: $(NAME)
print-srcs:
	@echo $(SRCS)

# Compilação do programa
$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(READLINE) -o $(NAME)

# Compilação da libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Regra bônus
bonus: $(LIBFT) $(OBJS) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(BONUS_OBJS) $(LIBFT) $(READLINE) -o $(NAME)

# Regras de compilação para subdiretórios
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(BUILTINS_DIR)/%.o: $(BUILTINS_DIR)/%.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(EXECUTOR_DIR)/%.o: $(EXECUTOR_DIR)/%.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(PARSER_DIR)/%.o: $(PARSER_DIR)/%.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(SIGNALS_DIR)/%.o: $(SIGNALS_DIR)/%.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(UTILS_DIR)/%.o: $(UTILS_DIR)/%.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(BONUS_DIR)/%.o: $(BONUS_DIR)/%.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

# Limpeza de arquivos objeto
clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	make -C $(LIBFT_DIR) clean

# Limpeza total
fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

# Recompilação
re: fclean all

.PHONY: all clean fclean re bonus

