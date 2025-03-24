# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/22 19:27:18 by vigde-ol          #+#    #+#              #
#    Updated: 2024/10/22 19:59:09 by vigde-ol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nome da biblioteca
NAME = libft.a

# Compilador e flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Arquivos de origem
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
	ft_strnstr.c ft_strlcpy.c ft_strlcat.c ft_memset.c ft_bzero.c \
	ft_memchr.c ft_memcpy.c ft_memcmp.c ft_memmove.c ft_toupper.c \
	ft_tolower.c ft_atoi.c ft_calloc.c ft_strdup.c \
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c 

# Arquivos bônus (listas encadeadas)
BONUS_SRCS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

# Gera os arquivos objetos
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# Regras do Makefile

# Regra all: Compila os arquivos e cria a biblioteca
all: $(NAME)

# Regra para compilar a biblioteca principal
$(NAME): $(OBJS) 
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)

# Regra para compilar os arquivos .o a partir dos .c
%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@
	
# Alvo bônus: compila a biblioteca incluindo os bônus
bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
	ranlib $(NAME)

# Regra clean: Remove os arquivos objetos (.o)
clean:
	rm -f $(OBJS) $(BONUS_OBJS)

# Regra fclean: Remove os arquivos objetos (.o) e a biblioteca (libft.a)
fclean: clean
	rm -f $(NAME)

# Regra re: Limpa tudo e recompila
re: fclean all

#unit-tester
so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS) $(BONUS_OBJS)

# Declaração de alvos que não são arquivos
.PHONY: all clean fclean re bonus
