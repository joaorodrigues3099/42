##############################################
#                Makefile for                #
#                Libft Library               #
##############################################

# File Variables
# ============================================

# Combine all source files
SRCS			= srcs/main.c \
				  srcs/utils.c \
				  srcs/tab.c \
				  srcs/checks.c \
				  srcs/ranges.c \
				  srcs/list/tab_to_list.c \
				  srcs/list/list_utils.c \
				  srcs/test.c \
				  srcs/operations/swap.c \
				  srcs/operations/push.c \
				  srcs/operations/rotate.c \
				  srcs/operations/rev_rotate.c \
				  srcs/operations/best_operations.c \
				  srcs/sort/sort_3.c \
				  srcs/sort/sort_100.c \
				  srcs/sort/sort_utils.c \

OBJS 			= $(SRCS:.c=.o)

# Compilation Variables
# ============================================

INCS    		= includes
NAME   			= push_swap
LIBC    		= ar rcs
CC      		= cc
CFLAGS  		= -Wall -Werror -Wextra -g
RM      		= rm -f

# Color Codes
PINK 			= \033[38;2;255;105;180m
RESET 			= \033[0m

##############################################
#               Main Commands                #
##############################################

# Default target, builds the library
all: libft $(NAME)

##############################################
#                Compilation Rules           #
##############################################

# Compile .c files into .o files
.c.o:
	@echo "$(PINK)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS)

libft:
	@echo "$(PINK)Compiling Libft...$(RESET)"
	make -C libft all

# Link all object files into the library archive
$(NAME): $(OBJS)
	@echo "$(PINK)Creating library $(NAME)...$(RESET)"
	$(CC) $(OBJS) -o $@ -Llibft -lft $(CFLAGS)

##############################################
#             Cleaning Commands              #
##############################################

# Remove object files
clean:
	@echo "$(PINK)Cleaning up object files...$(RESET)"
	$(RM) $(OBJS)
	make -C libft clean

# Full clean: remove library files as well
fclean: clean
	@echo "$(PINK)Removing $(NAME) and libft.so...$(RESET)"
	$(RM) $(NAME)
	make -C libft fclean

# Rebuild everything from scratch
re: fclean all

##############################################
#                Phony Targets               #
##############################################

.PHONY: libft all bonus so clean fclean re
