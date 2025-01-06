SRCS = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c
OBJS = ${SRCS:.c=.o}
INCS = includes
NAME = libft.a
LIBC = ar rc
LIBR = ranlib
CC = cc
RM = rm -f

.c.o:
		${CC} -c $< -o $@ -I ${INCS}

${NAME}: ${OBJS}
	${LIBC} $@ $^
	${LIBR} $@

all: ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: .c.o all clean fclean re
