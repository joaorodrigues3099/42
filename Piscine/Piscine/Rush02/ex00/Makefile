# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/27 10:51:30 by bpiovano          #+#    #+#              #
#    Updated: 2024/07/28 23:36:05 by joao-alm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES	= main.c ft_atoi.c print.c dic.c helpers.c
OBJECTS	= ${SOURCES:.c=.o}
INCLUDES	= cfiles
NAME	= rush-02
CC	= cc
RM	= rm -f
CFLAGS	= -Wall -Wextra -Werror -fPIE
LDFLAGS = -pie

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCLUDES}

${NAME}:	${OBJECTS}
			gcc -o ${NAME} ${OBJECTS} ${CFLAGS}

all: ${NAME}

clean:
	${RM} ${OBJECTS}

fclean: clean
	${RM} ${NAME}

re: fclean all

norm :
	norminette -R CheckForbiddenSourceHeader */*.[ch]

.PHONY: all clean fclean re .c.o norm
