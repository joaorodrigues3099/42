SRCS = $(wildcard srcs/*.c)
OBJS = ${SRCS:.c=.o}
NAME = ft_display_file
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

.c.o:
		${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
		${CC} ${CFLAGS} $^ -o ${NAME}

all: ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: .c.o all clean fclean re