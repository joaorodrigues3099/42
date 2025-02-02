NAME := philo

CC := cc
CFLAGS := -Wall -Werror -Wextra -g

SRCS := main.c \
		init.c \
		philo_utils.c \
		libft_utils/ft_atoi.c \
		libft_utils/ft_calloc.c \
		libft_utils/ft_isdigit.c \
		libft_utils/ft_isint.c \
		libft_utils/ft_now_ms.c \
		libft_utils/ft_strlen.c \
		libft_utils/ft_usleep.c \
		# philo_utils/philo_utils2.c 

OBJS := $(SRCS:.c=.o)

%.o: %.c
	@$(CC) -g $(CFLAGS) -c $< -o $@ -I./

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -pthread

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
